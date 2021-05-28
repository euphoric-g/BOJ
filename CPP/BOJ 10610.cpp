#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string str;
    int sum = 0;
    std::cin >> str;
    for(int i=0; i<str.size(); i++) sum += str[i] - '0';
    std::sort(str.begin(), str.end(), [](const char &a, const char &b) {
        return a > b;
    });
    if(sum != 0 && sum % 3 == 0 && *str.rbegin() == '0') {
        std::cout << str << '\n';
    } else {
        std::cout << "-1\n";
    }
    return 0;
}