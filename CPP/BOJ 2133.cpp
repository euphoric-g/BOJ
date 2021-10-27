#include <iostream>

using namespace std;

int dp[16][2];

int main() {
    int n;
    dp[1][0] = 3;
    for(int i=2; i<16; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) * 3;
        dp[i][1] = (dp[i-1][0] * 2 / 3) + dp[i-1][1];
    }
    cin >> n;
    if(n%2) {
        cout << "0\n";
        return 0;
    }
    /*
    for(int i=1; i<16; i++) cout << dp[i][0] << '\t';
    cout << endl;
    for(int i=1; i<16; i++) cout << dp[i][1] << '\t';
    cout << endl;
    */
    cout << (dp[n/2][0] + dp[n/2][1]) << '\n';
    return 0;
}