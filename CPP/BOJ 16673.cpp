#include <iostream>

int main() {
    int c, k, p;
    std::cin >> c >> k >> p;
    std::cout << (((c*(c+1)*(2*c+1))/6)*p + ((c*(c+1))/2)*k) << '\n';
}