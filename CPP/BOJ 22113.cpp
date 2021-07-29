#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> route(m, 0);
    for(int i=0; i<m; i++) {
        std::cin >> route[i];
    }
    int cost[101][101];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> cost[i][j];
        }
    }
    int start = route[0]-1;
    int sum = 0;
    for(int i=1; i<route.size(); i++) {
        sum += cost[start][route[i]-1];
        start = route[i]-1;
    }
    std::cout << sum << '\n';
}