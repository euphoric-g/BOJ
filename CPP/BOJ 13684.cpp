#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    while(1) {
        int k;
        std::cin >> k;
        if(k == 0) break;
        int n, m;
        std::cin >> n >> m;
        while(k--) {
            int x, y;
            std::cin >> x >> y;
            x -= n;
            y -= m;
            if(x*y == 0) {
                std::cout << "divisa";
            } else if(x*y > 0) {
                if(x > 0) {
                    std::cout << "NE";
                } else {
                    std::cout << "SO";
                }
            } else {
                if(x > 0) {
                    std::cout << "SE";
                } else {
                    std::cout << "NO";
                }
            }
            std::cout << '\n';
        }
    }
}