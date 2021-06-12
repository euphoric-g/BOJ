#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    while(t--) {
        std::string s;
        std::getline(std::cin, s);
        auto loc = s.find(' ', 0);
        int sum = 0;
        while((loc = s.find(' ', 0)) != std::string::npos) {
            sum += std::stoi(s.substr(0, loc));
            s = s.substr(loc+1, s.size());
        }
        sum += std::stoi(s);
        std::cout << sum << '\n';
    }
    return 0;
}