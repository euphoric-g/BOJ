#include <iostream>
#include <algorithm>
#include <vector>

char *answer;
int cursor = 0;
int cur_all = 0;
int l, c;

void make(std::vector<char> all) {
    if(cursor == l) {
        int mos = 0, jas = 0;
        for(int i=0; i<l; i++) {
            if(answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u') {
                mos++;
            } else jas++;
        }
        if(mos >= 1 && jas >= 2) {
            for(int i=0; i<l; i++) std::cout << answer[i];
            std::cout << std::endl;
        }
    } else {
        for(int i=cur_all; i<all.size(); i++) {
            answer[cursor++] = all[i];
            int temp = cur_all;
            cur_all = i+1;
            make(all);
            cursor--;
            cur_all = temp;
        }
    }
}

int main() {
    std::cin >> l >> c;
    std::vector<char> all;
    for(int i=0; i<c; i++) {
        char in;
        std::cin >> in;
        all.push_back(in);
    }
    std::sort(all.begin(), all.end());
    answer = new char[l];
    make(all);
    delete answer;
}