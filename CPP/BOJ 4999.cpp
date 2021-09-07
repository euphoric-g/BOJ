#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    if(a.size() >= b.size()) std::cout << "go\n";
    else std::cout << "no\n";
}