#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

// #define DEBUG

#define L 0
#define R 1
#define U 2
#define D 3

const int BIT_L = 0b1 << L;
const int BIT_R = 0b1 << R;
const int BIT_U = 0b1 << U;
const int BIT_D = 0b1 << D;

int BITS_DIR[] = { BIT_L, BIT_R, BIT_U, BIT_D };

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int lineType[] = {
    BIT_D | BIT_R, // line 0
    BIT_L | BIT_D, // line 1
    BIT_U | BIT_R, // line 2
    BIT_U | BIT_L, // line 3
    BIT_U | BIT_D, // ilne 4
    BIT_L | BIT_R  // line 5
};

auto lineConnected = [](const int &lineDesc, int dir) -> bool {
    return (lineType[lineDesc] & BITS_DIR[dir]) > 0;
};

auto isValidPosition = [](const std::pair<int, int> &pos, int n) -> bool {
    return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < n;
};

auto opposite = [](const int &dir) -> int {
    switch(dir) {
        case L:
        return R;
        case R:
        return L;
        case D:
        return U;
        case U:
        return D;
    }
    return -EXIT_FAILURE;
};

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, k;
    bool visited[51][51];
    auto clear_all = [&n, &visited]() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = false;
            }
        }
    };
    int state[51][51];
    std::cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> state[i][j];
            visited[i][j] = false;
        }
    }
    if(k == 0) {
        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int dist = 0;
        if(!lineConnected(state[0][0], L) || !lineConnected(state[n-1][n-1], R)) {
            std::cout << -1 << '\n';
            return 0;
        }
        while(!q.empty()) {
            dist++;
            int sz = q.size();
            while(sz--) {
                auto get = q.front(); q.pop();
                if(get.first == n-1 && get.second == n-1) {
                    std::cout << dist << '\n';
                    return 0;
                }
                for(int d=0; d<4; d++) {
                    if(!lineConnected(state[get.first][get.second], d)) continue;
                    std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                    if(!isValidPosition(next, n) || !lineConnected(state[next.first][next.second], opposite(d)) || visited[next.first][next.second]) continue;
                    visited[next.first][next.second] = true;
                    q.push(next);
                }
            }
        }
        std::cout << -1 << '\n';
        return 0;
    } else {
        int min_dist = INT32_MAX;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<6; k++) {
                    // i, j 타일을 k번 타일로 교체
                    if(state[i][j] == k) continue;
                    int save = state[i][j];
                    #ifdef DEBUG
                    std::cout << state[i][j] << '\n';
                    std::cout << "Replace Tile(" << i << ", " << j << ") with tile type " << k << '\n';
                    #endif
                    clear_all();
                    state[i][j] = k;
                    if(!lineConnected(state[0][0], L) || !lineConnected(state[n-1][n-1], R)) {
                        state[i][j] = save;
                        continue;
                    }
                    std::queue<std::pair<int, int>> q;
                    q.push({0, 0});
                    visited[0][0] = true;
                    int dist = 0;
                    while(!q.empty()) {
                        int sz = q.size();
                        dist++;
                        while(sz--) {
                            auto get = q.front(); q.pop();
                            #ifdef DEBUG
                            std::cout << "visit (" << get.first << ", " << get.second << ") at dist = " << dist << '\n';
                            #endif
                            if(get.first == n-1 && get.second == n-1) min_dist = std::min(min_dist, dist);
                            for(int d=0; d<4; d++) {
                                if(!lineConnected(state[get.first][get.second], d)) continue;
                                #ifdef DEBUG
                                std::cout << "search direction " << d << '\n';
                                #endif
                                std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                                if(!isValidPosition(next, n) || !lineConnected(state[next.first][next.second], opposite(d)) || visited[next.first][next.second]) continue;
                                visited[next.first][next.second] = true;
                                #ifdef DEBUG
                                std::cout << "Push (" << next.first << ", " << next.second << ")\n";
                                #endif
                                q.push(next);
                            }
                        }
                    }
                    state[i][j] = save;
                }
            }
        }
        std::cout << (min_dist == INT32_MAX ? -1 : min_dist) << '\n';
        return 0;
    }
}