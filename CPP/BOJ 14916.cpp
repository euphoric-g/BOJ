#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if(n == 1 || n == 3) {
        std::cout << "-1\n";
        return 0;
    }
    int twos = 0;
    while(n % 5 != 0) {
        twos++;
        n -= 2;
    }
    std::cout << twos+n/5 << '\n';
    return 0;
}