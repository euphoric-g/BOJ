#include <iostream>
#include <algorithm>
#include <cmath>

int gcd(int a, int b) {
    if(b == 0) return a;
    if(b == 1) return 1;
    return gcd(b, a%b);
}

int main() {
    int eu, el, cx, c, x0;
    std::cin >> eu >> el >> cx >> c >> x0;
    if(cx == 0) {
        std::cout << c << '\n' << "0 0\n";
        return 0;
    }
    int limit = cx * x0 + c;
    int du = abs(eu), dl = abs(el * cx);
    int gcd_d = gcd(du, dl);
    du /= gcd_d, dl /= gcd_d;
    if(du > 100'000'000 || dl > 100'000'000) {
        du = 0, dl = 0;
    }
    std::cout << limit << '\n' << du << ' ' << dl << '\n';
}


/*
f(x) = 0x + 3000
x0 = 3
L = 3 * 0 + 3000
e = 5/4
delta = inf
*/