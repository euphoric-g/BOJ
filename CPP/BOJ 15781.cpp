#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int def1 = INT32_MIN, def2 = INT32_MIN;
    while(n--) {
        int def;
        std::cin >> def;
        def1 = std::max(def1, def);
    }
    while(m--) {
        int def;
        std::cin >> def;
        def2 = std::max(def2, def);
    }
    std::cout << def1 + def2 << '\n';
}