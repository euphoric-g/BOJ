#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    while(1) {
        std::string str;
        std::getline(std::cin, str);
        if(str == "END") break;
        std::string rev = str;
        std::reverse(rev.begin(), rev.end());
        std::cout << rev << '\n';
    }
}