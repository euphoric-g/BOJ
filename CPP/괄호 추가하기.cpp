#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <iterator>

#define CALC_ERROR INT32_MAX
#define PLUS INT32_MIN
#define MINUS INT32_MIN+1
#define MULTIPLY INT32_MIN+2
#define OPEN INT32_MIN+3
#define CLOSE INT32_MIN+4
#define BAD INT32_MIN

bool isnum(int t) {
    return t != PLUS && t != MINUS && t != MULTIPLY && t != OPEN && t != CLOSE && t != BAD && t != CALC_ERROR;
}

void print_eq(std::queue<int> q) {
    while(!q.empty()) {
        int get = q.front();
        q.pop();
        if(isnum(get)) {
            std::cout << std::to_string(get);
        } else {
            switch(get) {
                case PLUS:
                std::cout << "+";
                break;
                case MINUS:
                std::cout << "-";
                break;
                case MULTIPLY:
                std::cout << "*";
                break;
                case OPEN:
                std::cout << "(";
                break;
                case CLOSE:
                std::cout << ")";
                break;
            }
        }
    }
    std::cout << std::endl;
}

int calc(std::queue<int> str) {
    std::queue<int> copied = str;
    std::vector<int> q;
    q.push_back(copied.front());
    copied.pop();
    while(!copied.empty()) {
        int get = copied.front();
        copied.pop();
        if(get == PLUS || get == MINUS || get == MULTIPLY) {
            q.push_back(get);
        } else {
            int operation = q.back(); q.pop_back();
            int front = q.back(); q.pop_back();
            switch(operation) {
                case PLUS :
                q.push_back(front+get);
                break;
                case MINUS :
                q.push_back(front-get);
                break;
                case MULTIPLY :
                q.push_back(front*get);
                break;
            }
        }
    }
    if(q.size() != 1) return CALC_ERROR;
    else return q.back();
}

std::queue<int> remove_brackets(std::queue<int> eq) {
    std::vector<int> veq;
    while(!eq.empty()) {
        veq.push_back(eq.front()); eq.pop();
    }
    std::vector<int>::iterator open = std::find(veq.begin(), veq.end(), OPEN);
    while(open != veq.end()) {
        std::vector<int>::iterator close = std::find(open, veq.end(), CLOSE);
        // 0 1 2 3 4 5 6 7 8 9 10
        // 3 * 2 + ( 8 - 4 ) * 3
        //         ^ open  ^ close
        //         (4)     (8)
        std::queue<int> subeq;
        for(std::vector<int>::iterator it = open + 1; it < close; it++) {
            subeq.push(*it);
        }
        int ans = calc(subeq);
        std::vector<int> new_veq;
        for(std::vector<int>::iterator it = veq.begin(); it < open; it++) {
            new_veq.push_back(*it);
        }
        new_veq.push_back(ans);
        for(std::vector<int>::iterator it = close+1; it < veq.end(); it++) {
            new_veq.push_back(*it);
        }
        veq = new_veq;
        open = std::find(veq.begin(), veq.end(), OPEN);
    }
    std::queue<int> ret;
    for(std::vector<int>::iterator it = veq.begin(); it != veq.end(); it++) {
        ret.push(*it);
    }
    return ret;
}

int bruteforce(std::queue<int> eq, std::queue<int> cur, int loc, bool open) {
    int local_loc = loc;
    std::queue<int> backup = eq;
    if(eq.size() < loc) {
        if(open) return BAD;
        else {
            return calc(remove_brackets(cur));
        }
    } else {
        std::queue<int> copied = cur;
        for(int i=0; i<loc; i++) eq.pop();
        bool opened = open;
        while(!eq.empty()) {
            int get = eq.front(); eq.pop();
            if(isnum(get)) {
                if(opened) {
                    copied.push(get);
                    copied.push(CLOSE);
                    opened = false;
                    local_loc++;
                } else {
                    std::queue<int> no_open = copied;
                    no_open.push(get);
                    int ret1 = bruteforce(backup, no_open, local_loc+1, false);
                    copied.push(OPEN);
                    copied.push(get);
                    int ret2 = bruteforce(backup, copied, local_loc+1, true);
                    if(!isnum(ret1) && !isnum(ret2)) return BAD;
                    if(!isnum(ret1) && isnum(ret2)) return ret2;
                    if(isnum(ret1) && !isnum(ret2)) return ret1;
                    if(isnum(ret1) && isnum(ret2)) {
                        return ret1 > ret2 ? ret1 : ret2;
                    }
                }
            } else {
                copied.push(get);
                local_loc++;
            }
        }
        if(!opened) {
            return bruteforce(eq, copied, local_loc, false);
        }
    }
    return BAD;
}

int main() {
    int n;
    std::cin >> n;
    std::queue<int> eq;
    for(int i=0; i<n; i++) {
        char in;
        std::cin >> in;
        switch(in) {
            case '+':
            eq.push(PLUS);
            break;
            case '-':
            eq.push(MINUS);
            break;
            case '*':
            eq.push(MULTIPLY);
            break;
            default:
            eq.push(in-'0');
        }
    }
    std::queue<int> cur;
    std::cout << bruteforce(eq, cur, 0, false) << std::endl;
}