#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    bool check[101][101];
    bool board[101][101];
    int limit = n*n - n;
    if(k > limit) {
        std::cout << "NO\n";
        return 0;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            check[i][j] = (i==j) ? false : true;
            board[i][j] = false;
        }
    }
    if(n%2 == 0) {
        check[n/2][n-1-n/2] = false;
        check[n/2][n-n/2] = true;
        check[n/2-1][n-n/2] = false;
        check[n/2-1][n-n/2-1] = true;
    }
    int cur = 0;
    int checked = 0;
    while(checked < k) {
        if(check[cur/n][cur%n]) {
            board[cur/n][cur%n] = true;
            checked++;
        }
        cur++;
    }
    std::cout << "YES\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << (board[i][j] ? '#' : '.');
        }
        std::cout << '\n';
    }
    return 0;
}