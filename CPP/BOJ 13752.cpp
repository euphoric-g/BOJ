#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    while(n--) {
        int k;
        std::cin >> k;
        std::cout << std::string(k, '=') << '\n';
    }
    return 0;
}