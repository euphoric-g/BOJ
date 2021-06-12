#include <iostream>

typedef long long ll;
int main() {
    ll n;
    std::cin >> n;
    ll num = 1;
    for(ll i=1; i<=n; i++) {
        num *= i;
        num %= 10000000;
        while(num % 10 == 0) num /= 10;
    }
    std::cout << (num % 10) << '\n';
    return 0;
}