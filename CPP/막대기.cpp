#include <iostream>

int main() {
    int x;
    std::cin >> x;
    int cnt = 0;
    while(x != 0) {
        if(x%2 == 1) cnt++;
        x /= 2;
    }
    std::cout << cnt << '\n';
}