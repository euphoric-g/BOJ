#include <iostream>
#include <string>
#include <stack>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::string base_2;
    std::cin >> base_2;
    std::stack<int> base_8;
    while(base_2.size() > 2) {
        int d = base_2.back() - '0'; base_2.pop_back();
        d += 2*(base_2.back() - '0'); base_2.pop_back();
        d += 4*(base_2.back() - '0'); base_2.pop_back();
        base_8.push(d);
    }
    if(base_2.size() == 1) {
        base_8.push(base_2.back()-'0'); base_2.pop_back();
    } else if(base_2.size() == 2) {
        int d = base_2.back() - '0'; base_2.pop_back();
        d += 2*(base_2.back() - '0'); base_2.pop_back();
        base_8.push(d);
    }
    while(!base_8.empty()) {
        std::cout << base_8.top();
        base_8.pop();
    }
    std::cout << '\n';
    return 0;
}