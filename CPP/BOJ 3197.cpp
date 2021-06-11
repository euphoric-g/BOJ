#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>

#define WATER '.'
#define ICE 'X'
#define SWAN 'L'

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char state[1501][1501];
bool visited[1501][1501];
int dist[1501][1501];
std::vector<std::pair<int, int>> swan_loc;

int r, c;

auto clear_all = []() {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            visited[i][j] = false;
        }
    }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin >> r >> c;
    auto pos_check = [](const std::pair<int, int> &pos) -> bool {
        return pos.first >= 0 && pos.first < r && pos.second >= 0 && pos.second < c;
    };
    std::queue<std::pair<int, int>> q;
    for(int i=0; i<r; i++) {
        std::string input;
        std::cin >> input;
        for(int j=0; j<c; j++) {
            state[i][j] = input[j];
            if(state[i][j] == SWAN) {
                dist[i][j] = 0;
                q.push({i, j});
                visited[i][j] = true;
                swan_loc.push_back({i, j});
            } else if(state[i][j] == WATER) {
                dist[i][j] = 0;
                q.push({i, j});
                visited[i][j] = true;
            } else if(state[i][j] == ICE) {
                dist[i][j] = INT32_MAX;
            }
        }
    }
    int time = 0;
    while(!q.empty()) {
        int sz = q.size();
        time++;
        while(sz--) {
            auto get = q.front(); q.pop();
            for(int d=0; d<4; d++) {
                int nx = get.first + dx[d], ny = get.second + dy[d];
                if(pos_check({nx, ny}) && !visited[nx][ny] && state[nx][ny] == ICE) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = time;
                    q.push({nx, ny});
                }
            }
        }
    }
    int l = 0, r = 3000, m;
LOOP:
    while(l < r) {
        m = (l+r)/2;
        // std::cout << "start at (l, m, r) = (" << l << ", " << m << ", " << r << ")\n";
        clear_all();
        std::queue<std::pair<int, int>> q;
        q.push(swan_loc[0]);
        while(!q.empty()) {
            auto get = q.front(); q.pop();
            if(get == swan_loc[1]) {
                // std::cout << m << '\n';
                r = m;
                // std::cout << "find at m = " << m << '\n';
                goto LOOP;
            }
            for(int d=0; d<4; d++) {
                int nx = get.first + dx[d], ny = get.second + dy[d];
                if(pos_check({nx, ny}) && !visited[nx][ny] && dist[nx][ny] <= m) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        l = m+1;
    }
    std::cout << l << '\n';
    return 0;
}