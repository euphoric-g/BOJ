#include <iostream>
#include <queue>
#include <string>

#define OPEN '('
#define CLOSE ')'

int main() {
    std::string str;
    std::cin >> str;
    std::queue<char> q;
    int level = 0;
    int pieces = 0;
    for(int i=0; i<str.size(); i++) {
        q.push(str[i]);
    }
    while(!q.empty()) {
        char get = q.front(); q.pop();
        char next = q.front();
        if(get == OPEN && next == CLOSE) {
            q.pop();
            pieces += level;
        } else if(get == OPEN && next != CLOSE) {
            level++;
        } else if(get == CLOSE) {
            level--;
            pieces++;
        }
    }
    std::cout << pieces << '\n';
}