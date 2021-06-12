#include <iostream>

int main() {
    int n, k, available = 0;
    std::cin >> n >> k;
    while(k--) {
        int holes;
        std::cin >> holes;
        available += (holes+1)/2;
    }
    std::cout << (available >= n ? "YES\n" : "NO\n");
}