#include <iostream>

int main() {
    int n, f;
    std::cin >> n >> f;
    int nmin = (n/100) * 100;
    for(int i=nmin; i<=INT32_MAX; i++) {
        if(i%f == 0) {
            std::cout << (i/10)%10 << i%10 << '\n';
            return 0;
        }
    }
}