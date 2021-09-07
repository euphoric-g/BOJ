#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while(n--) {
        int i, f;
        std::cin >> i >> f;
        if(i + f <= 3 && i <= 2 && f <= 2) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
}