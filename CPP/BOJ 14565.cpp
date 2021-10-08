#include <iostream>
#include <algorithm>
#include <tuple>

typedef long long ll;

std::tuple<ll, ll, ll> extended_euclidean(ll a, ll b) {
    if(b == 0) {
        return std::make_tuple(a, 1, 0);
    }
    ll g, x, y;
    std::tie(g, x, y) = extended_euclidean(b, a%b);
    return std::make_tuple(g, y, x-(a/b)*y);
}

int main() {
    ll n, a;
    std::cin >> n >> a;
    ll x, y, z;
    std::tie(x, y, z) = extended_euclidean(n, a);
    // a*c % n = 1
    // a*c + k*n = 1

    // 26 11
    // 11*c + 26*k = 1
    // 11, 26 -> 11, 5 -> 1, 5 ->
    std::cout << n-a << " " << (x != 1 ? -1 : (z > 0 ? z : z+n)) << std::endl;
}