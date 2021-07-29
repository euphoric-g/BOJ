#include <iostream>

int main() {
    int n, cnt = 0;
    std::cin >> n;
    while(n % 5 != 0 && n >= 0) {
        n -= 3;
        cnt++;
    }
    if(n < 0) std::cout << -1;
    else std::cout << cnt + n/5;
}