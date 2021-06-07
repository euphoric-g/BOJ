#include <iostream>
#include <string>

int gcd(int a, int b) {
    if(b == 0) return a;
    if(b == 1) return 1;
    return gcd(b, a%b);
}

int main () {
    std::string str;
    std::cin >> str;
    auto loc = str.find(':', 0);
    int a = std::stoi(str.substr(0, loc));
    int b = std::stoi(str.substr(loc+1, str.size()));
    int GCD = gcd(a, b);
    std::cout << a/GCD << ':' << b/GCD << '\n';
}