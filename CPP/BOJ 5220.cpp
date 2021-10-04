#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        int n, cb;
        std::cin >> n >> cb;
        while(n != 0) {
            cb += n % 2;
            n /= 2;
        }
        if(cb % 2) std::cout << "Corrupt\n";
        else std::cout << "Valid\n";
    }
}