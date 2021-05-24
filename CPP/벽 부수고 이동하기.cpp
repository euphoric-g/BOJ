#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#define BLANK '0'
#define WALL '1'
#define WITHOUT_BREAK 0
#define BROKED 1
#define IMPOSSIBLE INT32_MAX

typedef std::pair<int, int> pair;
typedef std::tuple<int, int, int> tuple;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

char state[1001][1001];
int dist[1001][1001][2];
bool visited[1001][1001][2];

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    int time = 0;
    std::cin >> n >> m;
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<m; j++) {
            state[i][j] = str[j];
            dist[i][j][WITHOUT_BREAK] = IMPOSSIBLE;
            dist[i][j][BROKED] = IMPOSSIBLE;
            visited[i][j][WITHOUT_BREAK] = false;
            visited[i][j][BROKED] = false;
        }
    }
    std::queue<tuple> q;
    q.push(std::make_tuple(0, 0, WITHOUT_BREAK));
    visited[0][0][WITHOUT_BREAK] = true;
    while(!q.empty()) {
        int qs = q.size();
        time++;
        while(qs-->0) {
            int x, y, f;
            std::tie(x, y, f) = q.front(); q.pop();
            dist[x][y][f] = std::min(time, dist[x][y][f]);
            // std::cout << "current position : (" << x << ", " << y << ", " << f << ")\n";
            for(int d=0; d<4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny][f]) {
                    if(state[nx][ny] == WALL && f == WITHOUT_BREAK) {
                        q.push(std::make_tuple(nx, ny, BROKED));
                        visited[nx][ny][BROKED] = true;
                    } else if(state[nx][ny] == BLANK) {
                        q.push(std::make_tuple(nx, ny, f));
                        visited[nx][ny][f] = true;
                    }
                }
            }
        }
    }
    if(dist[n-1][m-1][WITHOUT_BREAK] == IMPOSSIBLE && dist[n-1][m-1][BROKED] == IMPOSSIBLE) {
        std::cout << "-1\n";
    } else {
        std::cout << std::min(dist[n-1][m-1][WITHOUT_BREAK], dist[n-1][m-1][BROKED]) << '\n';
    }
    return 0;
}