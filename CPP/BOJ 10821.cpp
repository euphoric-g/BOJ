#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for(const auto &ch : s) cnt = ch == ',' ? cnt + 1 : cnt;
    std::cout << ++cnt << '\n';
    return 0;
}