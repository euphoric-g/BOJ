#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::string ret = "";
    while(t != 0) {
        ret += std::to_string(t % 9);
        t /= 9;
    }
    for(auto it = ret.rbegin(); it != ret.rend(); it++) {
        std::cout << *it;
    }
    std::cout << '\n';
}