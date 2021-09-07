#include <iostream>

int main() {
    int n, len = 0;
    std::cin >> n;
    while((n >> len) != 0) len++;
    for(int i=0; i<len; i++) {
        if((n & (1 << i)) != 0) std::cout << i << ' ';
    }
    std::cout << '\n';
}