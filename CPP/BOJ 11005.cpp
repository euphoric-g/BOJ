#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n, b;
    std::cin >> n >> b;
    std::string converted = "";
    auto int_to_char = [](int n) -> char {
        if(n < 10) return '0' + n;
        else return 'A' + n - 10;
    };
    while(n != 0) {
        converted += int_to_char(n % b);
        n /= b;
    }
    std::reverse(converted.begin(), converted.end());
    std::cout << converted << '\n';
}