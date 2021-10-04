#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        long long num;
        cin >> num;
        if(i == 0) dp[i] = num;
        else dp[i] = dp[i-1] + num;
    }
    long long max_earn = 0;
    for(int i=m; i<=n; i++) {
        max_earn = std::max(max_earn, dp[i] - dp[i-m]);
    }
    std::cout << max_earn << '\n';
}