#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    long long prize = 100;
    for(int i=1; i<=n; i++) {
        std::cout << prize << '\n';
        prize *= 2;
        long long copy = prize;
        int digits = 0;
        while(copy != 0) {
            copy /= 10;
            digits++;
        }
        digits = (digits+1)/2;
        // 12800, digits = 5 -> 3
        // pow(10, digits) = 1000
        // 12800 / 1000 * 1000 = 12000
        // 12800 != 12000 -> 13000
        int tmp = pow(10, digits);
        if(prize/tmp*tmp != prize) prize = prize/tmp*tmp+tmp;
    }
}