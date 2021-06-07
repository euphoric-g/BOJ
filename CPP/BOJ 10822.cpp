#include <iostream>
#include <string>

int main() {
    int sum = 0;
    std::string s;
    std::cin >> s;
    auto loc = s.find(',', 0);
    while(loc != std::string::npos) {
        sum += std::stoi(s.substr(0, loc));
        s = s.substr(loc+1, s.size());
        loc = s.find(',', 0);
    }
    sum += std::stoi(s);
    std::cout << sum << '\n';
}