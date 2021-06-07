#include <iostream>
#include <queue>

#define IMPOSSIBLE INT32_MAX
#define RIPEN 1
#define RAW 0
#define BLANK -1

typedef std::pair<int, int> pair;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int state[1001][1001];
bool visited[1001][1001];
int dist[1001][1001];

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int m, n;
    std::cin >> m >> n;
    std::queue<pair> q;
    bool raw_check = false;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cin >> state[i][j];
            visited[i][j] = false;
            dist[i][j] = IMPOSSIBLE;
            if(state[i][j] == RIPEN) {
                visited[i][j] = true;
                q.push(pair(i, j));
            } else if(state[i][j] == RAW) raw_check = true;
        }
    }
    if(!raw_check) {
        std::cout << "0\n";
        return 0;
    }
    int time = -1;
    while(!q.empty()) {
        int sz = q.size();
        time++;
        while(sz-->0) {
            pair get = q.front(); q.pop();
            dist[get.first][get.second] = std::min(dist[get.first][get.second], time);
            for(int d=0; d<4; d++) {
                pair next = pair(get.first + dx[d], get.second + dy[d]);
                if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < m) {
                    if(!visited[next.first][next.second] && state[next.first][next.second] != BLANK) {
                        visited[next.first][next.second] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    int max_dist = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(state[i][j] == RAW && dist[i][j] == IMPOSSIBLE) {
                std::cout << "-1\n";
                return 0;
            } else if(state[i][j] == RAW) {
                max_dist = std::max(max_dist, dist[i][j]);
            }
        }
    }
    std::cout << max_dist << '\n';
    return 0;
}