#include <iostream>
#include <vector>
#include <queue>

const int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1};
const int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    auto pos_check = [](int l, const std::pair<int, int> &pos) -> bool {
        return pos.first >= 0 && pos.first < l && pos.second >= 0 && pos.second < l;
    };
    while(t-->0) {
        int l, sx, sy, ex, ey;
        std::cin >> l >> sx >> sy >> ex >> ey;
        std::queue<std::pair<int, int>> q;
        bool visited[301][301];
        for(int i=0; i<301; i++) {
            for(int j=0; j<301; j++) {
                visited[i][j] = false;
            }
        }
        int dist = -1;
        bool find = false;
        visited[sx][sy] = true;
        q.push({sx, sy});
        while(!q.empty() && !find) {
            dist++;
            int sz = q.size();
            while(sz-->0) {
                auto get = q.front(); q.pop();
                if(get.first == ex && get.second == ey) {
                    find = true;
                    break;
                }
                for(int d=0; d<8; d++) {
                    std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                    if(pos_check(l, next) && !visited[next.first][next.second]) {
                        visited[next.first][next.second] = true;
                        q.push(next);
                    }
                }
            }
        }
        std::cout << dist << '\n';
    }
}