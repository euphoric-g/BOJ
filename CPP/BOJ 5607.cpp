#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int a = 0, b = 0;
    while(n--) {
        int c1, c2;
        std::cin >> c1 >> c2;
        if(c1 > c2) a += c1 + c2;
        else if(c1 < c2) b += c1 + c2;
        else { a += c1; b += c2; }
    }
    std::cout << a << ' ' << b << '\n';
}