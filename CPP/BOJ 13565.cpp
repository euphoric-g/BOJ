#include <iostream>
#include <vector>
#include <queue>
#include <string>

int state[1001][1001];
bool visited[1001][1001];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const int BLANK = '0', WALL = '1';

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<m; j++) {
            state[i][j] = str[j];
            visited[i][j] = false;
        }
    }
    std::queue<std::pair<int, int>> q;
    for(int i=0; i<m; i++) {
        if(state[0][i] == BLANK) {
            q.push({0, i});
            visited[0][i] = true;
        }
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            std::pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};
            if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < m && state[next.first][next.second] == BLANK && !visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
    bool percolate_check = false;
    int ind = 0;
    while(!percolate_check && ind < m) {
        percolate_check = visited[n-1][ind++] ? true : percolate_check;
    }
    std::cout << (percolate_check ? "YES\n" : "NO\n");
}