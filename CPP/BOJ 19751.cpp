#include <iostream>
#include <algorithm>

int main() {
    int n[4];
    for(int i=0; i<4; i++) std::cin >> n[i];
    std::sort(n, n+4);
    std::cout << n[0] << ' ' << n[2] << ' ' << n[1] << ' ' << n[3] << '\n';
}