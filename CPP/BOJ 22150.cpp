#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        bool ans = false;
        std::cin >> n;
        for(int i=0; i<n; i++) {
            int l, r;
            std::cin >> l >> r;
            if(l + r != n) ans = true;
        }
        std::cout << (ans ? "yes\n" : "no\n");
    }
}