#include <iostream>
#include <string>

int main() {
    std::string format;
    std::cin >> format;
    auto kind = [](char ch) -> int { return ch == 'c' ? 26 : 10; };
    int kinds = kind(format[0]);
    char last = format[0];
    int cnt = 1;
    for(int i=1; i<format.size(); i++) {
        if(format[i] != last) {
            kinds *= kind(format[i]);
            cnt = 1;
        } else {
            kinds *= kind(format[i]) - 1;
        }
        last = format[i];
    }
    std::cout << kinds << '\n';
    return 0;
}