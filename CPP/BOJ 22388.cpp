#include <iostream>
#include <string>

int main() {
    while(1) {
        std::string g;
        std::cin >> g;
        if(g == "#") break;
        int y, m, d;
        std::cin >> y >> m >> d;
        if(y >= 32) {
            std::cout << "? " << y-30 << ' ' << m << ' ' << d << '\n';
        } else if(y==31 && m>=5) {
            std::cout << "? 1 " << m << ' ' << d << '\n';
        } else {
            std::cout << g << ' ' << y << ' ' << m << ' ' << d << '\n';
        }
    }
}