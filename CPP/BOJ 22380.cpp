#include <iostream>

int main() {
    while(1) {
        int n, m;
        std::cin >> n >> m;
        if(n == 0 && m == 0) break;
        int sum = 0, need = m/n;
        while(n--) {
            int account;
            std::cin >> account;
            sum += (account >= need ? need : account);
        }
        std::cout << sum << '\n';
    }
}