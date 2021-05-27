#include <iostream>

void func(int n) {
    while(n-->0) {
        std::cout << n << '\n';
    }
}

int main() {
    int n = 100;
    func(n);
    return 0;
}