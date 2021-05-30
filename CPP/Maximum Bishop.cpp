#include <iostream>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::cout << n + (n-2 > 0 ? n-2 : 0) << '\n';
    for(int i=1; i<=n; i++) {
        std::cout << 1 << ' ' << i << '\n';
    }
    for(int i=2; i<=n-1; i++) {
        std::cout << n << ' ' << i << '\n';
    }
    return 0;
}