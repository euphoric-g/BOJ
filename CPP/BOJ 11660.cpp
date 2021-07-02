#include <iostream>
#include <vector>

typedef long long ll;
ll **arr;
ll **dp;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    arr = new ll*[n];
    dp = new ll*[n];
    for(int i=0; i<n; i++) {
        arr[i] = new ll[n];
        dp[i] = new ll[n];
        for(int j=0; j<n; j++) {
            std::cin >> arr[i][j];
            if(i==0 && j==0) dp[i][j] = arr[i][j];
            else if(i == 0) dp[i][j] = dp[i][j-1] + arr[i][j];
            else if(j == 0) dp[i][j] = dp[i-1][j] + arr[i][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
            // std::cout << dp[i][j] << ' ';
        }
        // std::cout << '\n';
    }
    for(int i=0; i<m; i++) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1--, x2--, y1--, y2--;
        ll big = dp[x2][y2];
        ll small = dp[x1][y1];
        ll up = x1 > 0 ? dp[x1-1][y2] : 0;
        ll left = y1 > 0 ? dp[x2][y1-1] : 0;
        ll corner = (x1 > 0 && y1 > 0) ? dp[x1-1][y1-1] : 0;
        ll ans = big - left - up + corner;
        // std::cout << "(big, up, left, corner) = " << big << ' ' << up << ' ' << left << ' ' << corner << '\n';
        std::cout << ans << '\n';
    }
    delete[] arr;
    delete[] dp;
    return 0;
}