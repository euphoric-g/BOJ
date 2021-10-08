#include <iostream>

typedef long long ll;

ll pows[40] = {1, };

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    for(int i=1; i<40; i++) {
        pows[i] = 3*pows[i-1];
    }
    while(t--) {
        ll n;
        std::cin >> n;
        ll ans = 0;
        for(int i=0; i<40; i++) {
            if((n >> i) % 2 == 1) ans += pows[i];
        }
        std::cout << ans << '\n';
    }
}