#include <iostream>
#include <vector>

bool bad[201][201];

int main() {
    int n, m;
    std::cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        std::cin >> a >> b;
        bad[a][b] = 1;
        bad[b][a] = 1;
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            for(int k=j+1; k<=n; k++) {
                if(!bad[i][j] && !bad[j][k] && !bad[i][k]) cnt++;
            }
        }
    }
    std::cout << cnt << '\n';
}