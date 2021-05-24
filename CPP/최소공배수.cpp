#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    } else if(a % b == 0) {
        return std::min(a, b);
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    std::cin.tie(0);
    std::iostream::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t-->0) {
        int a, b;
        std::cin >> a >> b;
        int g = gcd(a, b);
        std::cout << g * (a/g) * (b/g) << std::endl;
    }
    return 0;
}