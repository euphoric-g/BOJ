#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int c = (std::max(a, b) + 1)/2;
    int d = std::min(a, b);
    std::cout << std::min(c, d) << ' ' << std::max(c, d) << '\n';
}