#include <iostream>

int main() {
    int x, k;
    std::cin >> x >> k;
    if(7*k <= x) {
        std::cout << 7000*k << '\n';
    } else if(7*k <= 2*x) {
        std::cout << 3500*k << '\n';
    } else if(7*k <= 4*x) {
        std::cout << 1750*k << '\n';
    } else {
        std::cout << 0 << '\n';
    }
}