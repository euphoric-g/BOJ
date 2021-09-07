#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while(n--) {
        int m, xs, ys, xf, yf;
        std::cin >> m >> xs >> ys >> xf >> yf;
        if(abs(xs-xf) + abs(ys-yf) > m) {
            std::cout << "Infinity\n";
        } else {
            std::cout << "First 1\n";
        }
    }
}