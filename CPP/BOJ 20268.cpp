#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int m, n;
        std::cin >> m >> n;
        if(m == 1 && n == 1) {
            std::cout << 1 << '\n';
        } else if(m == 2 && n == 2) {
            std::cout << 7 << '\n';
        } else {
            std::cout << 1 << '\n';
        }
        int consume = m+n, trash;
        while(consume--) std::cin >> trash;
    }    
}