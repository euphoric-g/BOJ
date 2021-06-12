#include <iostream>

typedef long long ll;

const ll P = 1'000'000'007LL;

ll factorial_mod_p(ll n) {
    ll ret = 1;
    for(ll i = 1; i <= n; i++) {
        ret *= i;
        ret %= P;
    }
    return ret;
}

ll power_mod_p(ll base, ll pow) {
    // std::cout << "power_mod_p(" << base << ", " << pow << ")\n";
    if(pow == 0) return 1;
    if(pow == 1) return base;
    ll half = power_mod_p(base, pow/2);
    if(pow % 2 == 0) {
        return (half * half) % P;
    }
    return (power_mod_p(base, pow-1) * base) % P;
}

int main() {
    ll n, k;
    std::cin >> n >> k;
    ll A = factorial_mod_p(n);
    ll B = (factorial_mod_p(k) * factorial_mod_p(n-k)) % P;
    // std::cout << A << ", " << B << '\n';
    ll B_powered = power_mod_p(B, P-2);
    std::cout << ((A * B_powered) % P) << '\n';
    return 0;
}