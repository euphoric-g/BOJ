#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string set[13];
    set[0] = "-";
    for(int i=1; i<13; i++) {
        set[i] = set[i-1] + std::string(set[i-1].size(), ' ') + set[i-1];
    }
    int n;
    while(std::cin >> n) {
        std::cout << set[n] << '\n';
    }
}