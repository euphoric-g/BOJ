#include <iostream>
#include <queue>
#include <string>
#include <tuple>

#define START 'S'
#define END 'E'
#define WALL '#'
#define BLANK '.'

typedef std::tuple<int, int, int> pos;

const int dx[] = {0, -1, 0, 1, 0, 0};
const int dy[] = {1, 0, -1, 0, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};


int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    while(1) {
        int h, n, m;
        int ez, ex, ey;
        std::cin >> h >> n >> m;
        if(h == 0 && n == 0 && m == 0) break;
        char arr[30][30][30];
        bool visited[30][30][30];
        int dist[30][30][30];
        std::queue<pos> q;
        for(int i=0; i<h; i++) {
            for(int j=0; j<n; j++) {
                std::string str;
                std::cin >> str;
                for(int k=0; k<m; k++) {
                    arr[i][j][k] = str[k];
                    dist[i][j][k] = INT32_MAX;
                    visited[i][j][k] = false;
                    if(arr[i][j][k] == START) {
                        q.push(std::make_tuple(i, j, k));
                        visited[i][j][k] = true;
                        arr[i][j][k] = BLANK;
                    } else if(arr[i][j][k] == END) {
                        arr[i][j][k] = BLANK;
                        ez = i, ex = j, ey = k;
                    }
                }
            }
        }
        auto pos_check = [&h, &n, &m](int &z, int &x, int &y) -> bool { 
            return x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < h;
        };
        auto visit_check = [&visited](int &z, int &x, int &y) -> bool { return !visited[z][x][y]; };
        auto state_check = [&arr](int &z, int &x, int &y) -> bool { return arr[z][x][y] == BLANK; };
        int time = -1;
        while(!q.empty()) {
            int sz = q.size();
            time++;
            while(sz-->0) {
                pos cur = q.front(); q.pop();
                int z, x, y;
                std::tie(z, x, y) = cur;
                dist[z][x][y] = std::min(dist[z][x][y], time);
                for(int d=0; d<6; d++) {
                    int nz = z + dz[d], ny = y + dy[d], nx = x + dx[d];
                    pos next = std::make_tuple(nz, nx, ny);
                    if(pos_check(nz, nx, ny) && visit_check(nz, nx, ny) && state_check(nz, nx, ny)) {
                        visited[nz][nx][ny] = true;
                        q.push(next);
                    }
                }
            }
        }
        int distance = dist[ez][ex][ey];
        if(distance == INT32_MAX) {
            std::cout << "Trapped!\n";
        } else {
            std::cout << "Escaped in " << distance << " minute(s).\n";
        }
    }    
    return 0;
}