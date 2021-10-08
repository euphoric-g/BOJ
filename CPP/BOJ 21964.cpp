#include <string>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;
    std::cout << str.substr(str.size()-5, 5) << '\n';
}