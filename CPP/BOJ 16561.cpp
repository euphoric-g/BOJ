#include <iostream>

int main() {
    int n, cnt = 0;
    std::cin >> n;
    n /= 3;
    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++) {
            if(a+b>=n) break;
            cnt++;
            // std::cout << a << ", " << b << ", " << n-a-b << '\n';
        }
    }
    std::cout << cnt << '\n';
}