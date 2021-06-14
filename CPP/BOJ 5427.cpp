#include <iostream>
#include <queue>
#include <string>

#define BLANK '.'
#define WALL '#'
#define FIRE '*'
#define START '@'

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int test_case;
    std::cin >> test_case;
    while(test_case--) {
        int w, h;
        std::cin >> w >> h;
        auto pos_check = [&w, &h](const std::pair<int, int> &pos) -> bool {
            return pos.first >= 0 && pos.first < h && pos.second >= 0 && pos.second < w;
        };
        char state[1001][1001];
        bool visited[1001][1001];
        int dist[1001][1001];
        std::queue<std::pair<int, int>> esc_q;
        std::queue<std::pair<int, int>> fire_q;
        for(int i=0; i<h; i++) {
            std::string str;
            std::cin >> str;
            for(int j=0; j<w; j++) {
                state[i][j] = str[j];
                visited[i][j] = false;
                dist[i][j] = INT32_MAX;
                if(state[i][j] == START) {
                    state[i][j] = BLANK;
                    esc_q.push({i, j});
                } else if(state[i][j] == FIRE) {
                    dist[i][j] = 0;
                    visited[i][j] = true;
                    fire_q.push({i, j});
                }
            }
        }
        int distance = -1;
        while(!fire_q.empty()) {
            int sz = fire_q.size();
            distance++;
            while(sz--) {
                auto get = fire_q.front(); fire_q.pop();
                for(int d=0; d<4; d++) {
                    int nx = get.first + dx[d], ny = get.second + dy[d];
                    if(pos_check({nx, ny}) && !visited[nx][ny] && state[nx][ny] != WALL) {
                        state[nx][ny] = FIRE;
                        visited[nx][ny] = true;
                        dist[nx][ny] = distance + 1;
                        fire_q.push({nx, ny});
                    }
                }
            }
        }
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                visited[i][j] = false;
                // std::cout << (state[i][j] == WALL ? "#" : std::to_string(dist[i][j]));
            }
            // std::cout << '\n';
        }
        distance = 0;
        bool escape = false;
        while(!esc_q.empty() && !escape) {
            int sz = esc_q.size();
            distance++;
            while(sz-- && !escape) {
                auto get = esc_q.front(); esc_q.pop();
                for(int d=0; d<4 && !escape; d++) {
                    int nx = get.first + dx[d], ny = get.second + dy[d];
                    if(pos_check({nx, ny}) && !visited[nx][ny] && state[nx][ny] != WALL && dist[nx][ny] > distance) {
                        visited[nx][ny] = true;
                        esc_q.push({nx, ny});
                    } else if(!pos_check({nx, ny})) {
                        escape = true;
                    }
                }
            }
        }
        if(escape) {
            std::cout << distance << '\n';
        } else {
            std::cout << "IMPOSSIBLE\n";
        }
    }
}