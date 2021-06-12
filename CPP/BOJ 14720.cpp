#include <iostream>

int main() {
    int n, need = 0, cnt = 0;
    std::cin >> n;
    while(n--) {
        int milk;
        std::cin >> milk;
        if(milk != need) continue;
        cnt++;
        need = (need+1) % 3;
    }
    std::cout << cnt << '\n';
    return 0;
}