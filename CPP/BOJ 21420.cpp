#include <iostream>

int main() {
    int zeros = 0, ones = 0;
    int n, state;
    std::cin >> n;
    while(n--) {
        std::cin >> state;
        if(state == 1) ones++;
        else zeros++;
    }
    std::cout << std::min(zeros, ones) << '\n';
}