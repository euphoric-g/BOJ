#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>

#define BLANK '.'
#define WALL '#'
#define HOLE 'O'
#define RED 'R'
#define BLUE 'B'

#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3

typedef std::vector<int> route;
typedef std::tuple<int, int, int, int, route> pos;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char dir_char[] = {'R', 'D', 'L', 'U'};

int n, m;
int hx, hy;
char arr[10][10];
bool visited[10][10][10][10];

pos move_sub(pos &cur, int &dir, char color) {
    int rx, ry, bx, by;
    route r;
    std::tie(rx, ry, bx, by, r) = cur;
    // std::cout << "move starts at " << rx << ", " << ry << ", " << bx << ", " << by << '\n';
    // std::cout << "direction : " << dir << '\n';
    if(color == RED) {
        while(1) {
            // std::cout << rx << ", " << ry << ", " << bx << ", " << by << '\n';
            if(rx == hx && ry == hy) return std::make_tuple(rx, ry, bx, by, r);
            int nx = rx + dx[dir], ny = ry + dy[dir];
            if(arr[nx][ny] == BLANK && !(nx == bx && ny == by)) {
                rx = nx, ry = ny;
            } else if(arr[nx][ny] == HOLE) {
                rx = nx, ry = ny;
            } else break;
        }
        return std::make_tuple(rx, ry, bx, by, r);
    } else {
        while(1) {
            // std::cout << rx << ", " << ry << ", " << bx << ", " << by << '\n';
            if(bx == hx && by == hy) return std::make_tuple(rx, ry, bx, by, r);
            int nx = bx + dx[dir], ny = by + dy[dir];
            if(arr[nx][ny] == BLANK && !(nx == rx && ny == ry)) {
                bx = nx, by = ny;
            } else if(arr[nx][ny] == HOLE) {
                bx = nx, by = ny;
            } else break;
        }
        return std::make_tuple(rx, ry, bx, by, r);
    }
}

pos move(pos cur, int dir) {
    pos ret = cur;
    ret = move_sub(ret, dir, RED);
    ret = move_sub(ret, dir, BLUE);
    ret = move_sub(ret, dir, RED);
    return ret;
}

int main() {
    int a, b, c, d;
    std::cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                for(int l=0; l<m; l++) {
                    visited[i][j][k][l] = false;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        std::string strin;
        std::cin >> strin;
        for(int j=0; j<m; j++) {
            arr[i][j] = strin[j];
            if(strin[j] == RED) {
                a = i, b = j;
                arr[i][j] = BLANK;
            } else if(strin[j] == BLUE) {
                c = i, d = j;
                arr[i][j] = BLANK;
            } else if(strin[j] == HOLE) {
                hx = i, hy = j;
            }
        }
    }
    auto tie = [](int &rx, int &ry, int &bx, int &by, route &route, pos tp) { std::tie(rx, ry, bx, by, route) = tp; };
    int time = -1;
    std::queue<pos> q;
    route r;
    visited[a][b][c][d] = true;
    q.push(std::make_tuple(a, b, c, d, r));
    while(!q.empty()) {
        int sz = q.size();
        if(++time > 10) break;
        while(sz-->0) {
            auto cur = q.front(); q.pop();
            int crx, cry, cbx, cby;
            route croute;
            tie(crx, cry, cbx, cby, croute, cur);
            // std::cout << "cur = " << crx << ", " << cry << ", " << cbx << ", " << cby << "\n";
            if(crx == hx && cry == hy) {
                std::cout << time << '\n';
                for(const auto &rt : croute) {
                    std::cout << dir_char[rt];
                }
                std::cout << '\n';
                return 0;
            }
            for(int dir=0; dir<4; dir++) {
                int nrx, nry, nbx, nby;
                route nroute;
                pos next = move(cur, dir);
                tie(nrx, nry, nbx, nby, nroute, next);
                // std::cout << "[" << dir << "] next : " << nrx << ", " << nry << ", " << nbx << ", " << nby << '\n';
                if(!visited[nrx][nry][nbx][nby]) {
                    visited[nrx][nry][nbx][nby] = true;
                    // 파란 구슬이 구멍에 빠졌다면 통과
                    // 빨간 구슬이 구멍에 빠졌다면 time 출력하고 return
                    if(!(nbx == hx && nby == hy)) {
                        nroute = croute;
                        nroute.push_back(dir);
                        q.push(std::make_tuple(nrx, nry, nbx, nby, nroute));
                    }
                }
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}