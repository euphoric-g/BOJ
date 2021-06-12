#include <iostream>

int main() {
    int a, time = 1;
    std::cin >> a;
    while(a != 1) {
        if(a%2) {
            a *= 3;
            a++;
        } else {
            a /= 2;
        }
        time++;
    }
    std::cout << time << '\n';
}