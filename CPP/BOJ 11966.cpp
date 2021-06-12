#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout << (__builtin_popcount(n) == 1 ? "1\n" : "0\n");
    return 0;
}