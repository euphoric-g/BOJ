#include <iostream>

#define NO_PAPER 0

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int arr[1001][1001];
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) arr[i][j] = NO_PAPER;
    }
    for(int i=1; i<=n; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        for(int x = a; x < a + c; x++) {
            for(int y = b; y < b+d; y++) {
                arr[x][y] = i;
            }
        }
    }
    int area[n+1] = {0, };
    for(int i=0; i<1001; i++) {
        for(int j=0; j<1001; j++) {
            area[arr[i][j]]++;
        }
    }
    for(int i=1; i<=n; i++) {
        std::cout << area[i] << '\n';
    }
}