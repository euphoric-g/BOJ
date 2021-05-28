#include <iostream>

int main() {
    unsigned long long n;
    std::cin >> n;
    std::cout << (n+1)*(n*(n-1)/2) << '\n';
    return 0;
}