#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m;
    while(std::cin >> n >> m) {
        if(n == 0 && m == 0) break;
        int total = n-m;
        int a = 0, b = (total % 2 && total >= 3) ? 1 : 0;
        total -= 3*b;
        a = total / 2;
        std::cout << a << ' ' << b << '\n';
    }
}