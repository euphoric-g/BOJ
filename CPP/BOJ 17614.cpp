#include <iostream>

int main() {
    int n, cnt = 0;
    std::cin >> n;
    for(int i=1; i<=n; i++) {
        int temp = i;
        while(temp != 0) {
            if(temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) cnt++;
            temp /= 10;
        }
    }
    std::cout << cnt << '\n';
}