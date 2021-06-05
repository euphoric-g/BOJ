#include <iostream>
#include <queue>
#include <vector>

#define BLANK 0

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    int state[201][201];
    bool visited[201][201];
    std::vector<std::queue<std::pair<int, int>>> qv(k+1);
    auto pos_check = [&n](const std::pair<int, int> &pos) -> bool {
        return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < n;
    };
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> state[i][j];
            visited[i][j] = false;
            if(state[i][j] > BLANK) {
                visited[i][j] = true;
                qv[state[i][j]].push({i, j});
            }
        }
    }
    int s, x, y, time = 0;
    std::cin >> s >> x >> y;
    while(time++ < s && state[x-1][y-1] == BLANK) {
        for(int i=1; i<=k; i++) {
            int sz = qv[i].size();
            while(sz--) {
                auto get = qv[i].front(); qv[i].pop();
                for(int d=0; d<4; d++) {
                    std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                    if(pos_check(next) && !visited[next.first][next.second] && state[next.first][next.second] == BLANK) {
                        visited[next.first][next.second] = true;
                        state[next.first][next.second] = i;
                        qv[i].push(next);
                    }
                }
            }
        }
    }
    std::cout << state[x-1][y-1] << '\n';
    return 0;
}