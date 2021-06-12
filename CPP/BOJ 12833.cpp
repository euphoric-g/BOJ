#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if(c % 2 == 0) {
        std::cout << a << '\n';
    } else {
        std::cout << (a ^ b) << '\n';
    }
}