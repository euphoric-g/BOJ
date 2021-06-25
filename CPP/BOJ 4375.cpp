#include <iostream>

typedef long long ll;

int main() {
    int n;
    while(std::cin >> n) {
        int cnt = 1;
        int mod = 1 % n;
        while(mod != 0) {
            mod *= 10;
            mod %= n;
            mod++;
            mod %= n;
            cnt++;
        }
        std::cout << cnt << '\n';
    }
}