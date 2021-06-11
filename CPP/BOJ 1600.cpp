#include <iostream>
#include <queue>
#include <tuple>

#define BLANK 0
#define WALL 1

const int horse_dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int horse_dy[] = {2, -2, 1, -1, 2, -2, 1, -1};
const int monkey_dx[] = {1, 0, -1, 0};
const int monkey_dy[] = {0, 1, 0, -1};

int state[201][201];
bool visited[201][201][31];

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int k, w, h;
    std::cin >> k >> w >> h;
    auto pos_check = [&w, &h](const std::pair<int, int> &pos) -> bool {
        return pos.first >= 0 && pos.first < h && pos.second >= 0 && pos.second < w;
    };
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            std::cin >> state[i][j];
        }
    }
    int dist = -1;
    std::queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(0, 0, k));
    while(!q.empty()) {
        int sz = q.size();
        dist++;
        while(sz--) {
            int x, y, horse_cnt;
            std::tie(x, y, horse_cnt) = q.front(); q.pop();
            if(x == h-1 && y == w-1) {
                std::cout << dist << '\n';
                return 0;
            }
            if(horse_cnt > 0) {
                for(int d=0; d<8; d++) {
                    int nx = x + horse_dx[d], ny = y + horse_dy[d];
                    if(pos_check({nx, ny}) && !visited[nx][ny][horse_cnt-1] && state[nx][ny] == BLANK) {
                        visited[nx][ny][horse_cnt-1] = true;
                        q.push(std::make_tuple(nx, ny, horse_cnt-1));
                    }
                }
            }
            for(int d=0; d<4; d++) {
                int nx = x + monkey_dx[d], ny = y + monkey_dy[d];
                if(pos_check({nx, ny}) && !visited[nx][ny][horse_cnt] && state[nx][ny] == BLANK) {
                    visited[nx][ny][horse_cnt] = true;
                    q.push(std::make_tuple(nx, ny, horse_cnt));
                }
            }
        }
    }
    std::cout << "-1\n";
}