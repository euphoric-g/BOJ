#include <iostream>

int main() {
    int z;
    std::cin >> z;
    while(z--) {
        int w, k;
        std::cin >> w >> k;
        std::cout << (w*k)/2 << '\n';
    }
}