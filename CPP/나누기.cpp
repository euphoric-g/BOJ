#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

typedef long long ll;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<ll> sum(n, 0);
    for(int i=0; i<n; i++) {
        std::cin >> sum[i];
        if(i != 0) sum[i] += sum[i-1];
    }
    if(sum[n-1] % 4 != 0) {
        std::cout << "0\n";
        return 0;
    }
    ll div = sum[n-1]/4;
    if(div == 0) {
        ll cnt = 0;
        for(int i=0; i<n; i++) {
            if(sum[i] == 0) cnt++;
        }
        std::cout << ((cnt-1) * (cnt-2) * (cnt-3)) / 6 << '\n';
        return 0;
    }
    std::vector<ll> divs = {div, div*2, div*3};
    ll dp[3] = {0, };
    for(int i=0; i<n; i++) {
        if(sum[i] == divs[0]) dp[0]++;
        else if(sum[i] == divs[1]) dp[1] += dp[0];
        else if(sum[i] == divs[2]) dp[2] += dp[1];
    }
    std::cout << dp[2] << '\n';
    return 0;
}