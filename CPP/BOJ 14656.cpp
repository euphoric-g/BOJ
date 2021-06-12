#include <iostream>

int main() {
    int n, cnt = 0;
    std::cin >> n;
    for(int i=1; i<=n; i++) {
        int num;
        std::cin >> num;
        if(i != num) cnt++;
    }
    std::cout << cnt << '\n';
}