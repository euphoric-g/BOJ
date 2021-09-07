#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    auto pow = [](int base, int p) -> int {
        int ret = 1;
        while(p--) ret *= base;
        return ret;
    };
    auto ctoi = [](char c) -> int {
        if(c <= '9') return c-'0';
        return c-'A'+10;
    };
    std::string n;
    int b;
    std::cin >> n >> b;
    int loc = 0;
    int ans = 0;
    while(!n.empty()) {
        auto get = ctoi(n.back());
        n.pop_back();
        ans += get * pow(b, loc++);
    }
    std::cout << ans << '\n';
}