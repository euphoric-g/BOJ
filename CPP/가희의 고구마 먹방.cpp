#include <iostream>
#include <queue>
#include <string>

#define BLANK '.'
#define WALL '#'
#define GAHUI 'G'
#define SWEETPOTATO 'S'

int r, c, t;
int max_scnt = 0;
bool visited[101][101];
int state[101][101];

std::vector<std::pair<int, int>> route;

const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {1, 0, -1, 0, 0};

void DFS(int depth, int scnt, std::pair<int, int> cur) {
    // std::cout << "DFS with depth = " << depth << ", scnt = " << scnt << ", cur = " << cur.first << ", " << cur.second << '\n';
    if(depth == 0) {
        int final_scnt = scnt;
        if(state[cur.first][cur.second] == SWEETPOTATO) final_scnt++;
        max_scnt = std::max(max_scnt, final_scnt);
        return;
    }
    for(int d=0; d<5; d++) {
        std::pair<int, int> next = {cur.first + dx[d], cur.second + dy[d]};
        if(next.first < 0 || next.first >= r || next.second < 0 || next.second >= c) continue;
        if(state[next.first][next.second] == WALL) continue;
        route.push_back(next);
        if(state[cur.first][cur.second] == SWEETPOTATO) {
            state[cur.first][cur.second] = BLANK;
            DFS(depth-1, scnt+1, next);
            state[cur.first][cur.second] = SWEETPOTATO;
        } else {
            DFS(depth-1, scnt, next);
        }
        route.pop_back();
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin >> r >> c >> t;
    std::pair<int, int> gahui;
    for(int i=0; i<r; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<c; j++) {
            state[i][j] = str[j];
            visited[i][j] = false;
            if(state[i][j] == GAHUI) {
                gahui = {i, j};
                visited[i][j] = true;
                state[i][j] = BLANK;
            }
        }
    }
    route.push_back(gahui);
    DFS(t, 0, gahui);
    std::cout << max_scnt << '\n';
}