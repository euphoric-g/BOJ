#include <iostream>
#include <vector>

int dp[1010] = {0, };
int arr[1010] = {0, };
int n;

int main() {
    std::cin >> n;
    for(int i=1; i<=n; i++) {
        std::cin >> arr[i];
        if(i==1) dp[i] = arr[i];
        else {
            // dp[i-1] = i-1개의 카드를 구매할때 가장 비싸게 구매할 수 있는 가격
            // arr[i] = 현재 카드팩의 가격
            // dp[i] = dp[1]+dp[i-1], dp[2]+dp[i-2], ... 모두 비교했을때 최댓값
            dp[i] = arr[i];
            for(int x=1; x<=i/2; x++) {
                dp[i] = std::max(dp[i], dp[x] + dp[i-x]);
            }
        }
    }
    std::cout << dp[n] << std::endl;
}