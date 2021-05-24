#include <iostream>
#include <vector>

int max(int a, int b, int c) {
    int d = std::max(a, b);
    return std::max(c, d);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t-->0) {
        int n;
        std::cin >> n;
        std::vector<int> up(n, 0);
        std::vector<int> down(n, 0);
        std::vector<int> dp0(n, 0);
        std::vector<int> dp1(n, 0);
        for(int i=0; i<n; i++) std::cin >> up[i];
        for(int i=0; i<n; i++) std::cin >> down[i];
        dp0[0] = up[0]; dp1[0] = down[0];
        dp0[1] = dp1[0] + up[1]; dp1[1] = dp0[0] + down[1];
        for(int i=2; i<n; i++) {
            dp0[i] = max(dp1[i-1], dp0[i-2], dp1[i-2]) + up[i];
            dp1[i] = max(dp0[i-1], dp0[i-2], dp1[i-2]) + down[i];
        }
        std::cout << std::max(dp0[n-1], dp1[n-1]) << '\n';
    }
}