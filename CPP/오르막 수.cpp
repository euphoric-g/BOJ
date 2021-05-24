#include <iostream>

int dp[1001][10];

int main() {
    int n;
    std::cin >> n;
    for(int i=0; i<10; i++) {
        dp[1][i] = 1;
    }
    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<=j; k++) {
                dp[i][j] += dp[i-1][k] % 10007;
            }
            dp[i][j] = dp[i][j] % 10007;
        }
    }
    int count = 0;
    for(int i=0; i<10; i++) {
        count += dp[n][i] % 10007;
    }
    std::cout << count % 10007 << '\n';
    return 0;
}