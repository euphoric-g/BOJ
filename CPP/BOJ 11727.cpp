#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int dp[1010];
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-2]*2 + dp[i-1]) % 10007;
    }
    std::cout << dp[n] << '\n';
}