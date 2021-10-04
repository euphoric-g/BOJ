#include <iostream>
#include <cmath>

int dp[120000];

int get(int n) {
    if(dp[n] != 200000) return dp[n];
    for(int i=1; i<=sqrt(n); i++) {
        dp[n] = std::min(dp[n], 1 + get(n-i*i));
    }
    return dp[n];
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    for(int i=0; i<120000; i++) dp[i] = 200000;
    for(int i=1; i*i < 120000; i++) {
        dp[i*i] = 1;
    }
    int n;
    std::cin >> n;
    std::cout << get(n) << '\n';
}