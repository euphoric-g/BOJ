#include <iostream>
#include <queue>
#include <cstdlib>

#define DIMENSION 11
#define DIFFS (2 * (DIMENSION))

#define RIPEN_TOMATO 1
#define RAW_TOMATO 0
#define BLANK -1

class Coordinate {
    public:
    int axis[DIMENSION];
    Coordinate(void) { for(int i=0; i<DIMENSION; i++) axis[i] = 0; }
    Coordinate(int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w) {
        axis[0] = m, axis[1] = n, axis[2] = o, axis[3] = p, axis[4] = q, axis[5] = r;
        axis[6] = s, axis[7] = t, axis[8] = u, axis[9] = v, axis[10] = w;
    }
    Coordinate(int which_axis, int co) {
        for(int i=0; i<DIMENSION; i++) axis[i] = 0;
        axis[which_axis] = co;
    }
    Coordinate operator+(const Coordinate &co) {
        Coordinate ret = *this;
        for(int i=0; i<DIMENSION; i++) ret.axis[i] += co.axis[i];
        return ret;
    }
    bool pos_check(const Coordinate &limit) {
        bool ret = true;
        for(int i=0; i<DIMENSION && ret; i++) {
            if(axis[i] < 0 || axis[i] >= limit.axis[i]) ret = false;
        }
        return ret;
    }
};

const Coordinate diff[] = {
    Coordinate(0, 1), Coordinate(0, -1),
    Coordinate(1, 1), Coordinate(1, -1),
    Coordinate(2, 1), Coordinate(2, -1),
    Coordinate(3, 1), Coordinate(3, -1),
    Coordinate(4, 1), Coordinate(4, -1),
    Coordinate(5, 1), Coordinate(5, -1),
    Coordinate(6, 1), Coordinate(6, -1),
    Coordinate(7, 1), Coordinate(7, -1),
    Coordinate(8, 1), Coordinate(8, -1),
    Coordinate(9, 1), Coordinate(9, -1),
    Coordinate(10, 1), Coordinate(10, -1)
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int m, n, o, p, q, r, s, t, u, v, w;
    std::cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
    Coordinate limit = Coordinate(w, v, u, t, s, r, q, p, o, n, m);
    int state[w][v][u][t][s][r][q][p][o][n][m];
    bool visited[w][v][u][t][s][r][q][p][o][n][m];
    int dist[w][v][u][t][s][r][q][p][o][n][m];
    std::queue<Coordinate> q_co;
    for(int ww=0; ww<w; ww++) {
        for(int vv=0; vv<v; vv++) {
            for(int uu=0; uu<u; uu++) {
                for(int tt=0; tt<t; tt++) {
                    for(int ss=0; ss<s; ss++) {
                        for(int rr=0; rr<r; rr++) {
                            for(int qq=0; qq<q; qq++) {
                                for(int pp=0; pp<p; pp++) {
                                    for(int oo=0; oo<o; oo++) {
                                        for(int nn=0; nn<n; nn++) {
                                            for(int mm=0; mm<m; mm++) {
                                                visited[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm] = false;
                                                dist[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm] = INT32_MAX;
                                                std::cin >> state[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm];
                                                if(state[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm] == RIPEN_TOMATO) {
                                                    visited[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm] = true;
                                                    dist[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm] = 0;
                                                    q_co.push(Coordinate(ww, vv, uu, tt, ss, rr, qq, pp, oo, nn, mm));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int time = 0;
    while(!q_co.empty()) {
        int sz = q_co.size();
        time++;
        while(sz--) {
            Coordinate get = q_co.front(); q_co.pop();
            for(int d=0; d<DIFFS; d++) {
                Coordinate next = get + diff[d];
                if(next.pos_check(limit) && !visited[next.axis[0]][next.axis[1]][next.axis[2]][next.axis[3]][next.axis[4]][next.axis[5]][next.axis[6]][next.axis[7]][next.axis[8]][next.axis[9]][next.axis[10]]
                && state[next.axis[0]][next.axis[1]][next.axis[2]][next.axis[3]][next.axis[4]][next.axis[5]][next.axis[6]][next.axis[7]][next.axis[8]][next.axis[9]][next.axis[10]] != BLANK) {
                    visited[next.axis[0]][next.axis[1]][next.axis[2]][next.axis[3]][next.axis[4]][next.axis[5]][next.axis[6]][next.axis[7]][next.axis[8]][next.axis[9]][next.axis[10]] = true;
                    dist[next.axis[0]][next.axis[1]][next.axis[2]][next.axis[3]][next.axis[4]][next.axis[5]][next.axis[6]][next.axis[7]][next.axis[8]][next.axis[9]][next.axis[10]] = time;
                    q_co.push(next);
                }
            }
        }
    }
    int time_max = 0;
    for(int ww=0; ww<w; ww++) {
        for(int vv=0; vv<v; vv++) {
            for(int uu=0; uu<u; uu++) {
                for(int tt=0; tt<t; tt++) {
                    for(int ss=0; ss<s; ss++) {
                        for(int rr=0; rr<r; rr++) {
                            for(int qq=0; qq<q; qq++) {
                                for(int pp=0; pp<p; pp++) {
                                    for(int oo=0; oo<o; oo++) {
                                        for(int nn=0; nn<n; nn++) {
                                            for(int mm=0; mm<m; mm++) {
                                                if(state[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm] != BLANK) {
                                                    time_max = std::max(time_max, dist[ww][vv][uu][tt][ss][rr][qq][pp][oo][nn][mm]);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(time_max == INT32_MAX) {
        std::cout << "-1\n";
    } else {
        std::cout << time_max << '\n';
    }
}