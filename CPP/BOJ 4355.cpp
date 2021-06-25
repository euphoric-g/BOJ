#include <iostream>
#include <cmath>

typedef long long ll;
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    while(1) {
        ll n;
        std::cin >> n;
        if(n == 0) break;
        ll phi = n;
        for(ll i=2; i<=n; i++) {
            if(i != n && i*i > n) i=n-1;
            if(n % i != 0) continue;
            while(n % i == 0) n /= i;
            phi /= i;
            phi *= (i-1);
        }
        std::cout << phi << '\n';
    }
}