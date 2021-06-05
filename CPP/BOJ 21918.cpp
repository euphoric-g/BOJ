#include <iostream>
#include <bitset>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::bitset<4001> bulbs;
    for(int i=1; i<=n; i++) {
        int state;
        std::cin >> state;
        bulbs[i] = state;
    }
    for(int i=0; i<m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if(a == 1) {
            bulbs[b] = c;
        } else if (a == 2) {
            for(int j=b; j<=c; j++) bulbs[j].flip();
        } else if (a == 3) {
            for(int j=b; j<=c; j++) bulbs[j] = 0;
        } else if (a == 4) {
            for(int j=b; j<=c; j++) bulbs[j] = 1;
        }
    }
    for(int i=1; i<=n; i++) {
        std::cout << (bulbs[i] ? "1 " : "0 ");
    }
    std::cout << '\n';
    return 0;
}