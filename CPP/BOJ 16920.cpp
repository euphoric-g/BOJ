#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

#define BLANK '.'
#define WALL '#'

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<int> s(p, 0);
    char state[1000][1000];
    bool visited[1000][1000];
    auto pos_check = [&n, &m](const std::pair<int, int> &p) -> bool { 
        return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
    };
    auto show = [&state, &n, &m]() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                std::cout << state[i][j] << ' ';
            }
            std::cout << '\n';
        }
    };
    std::vector<std::queue<std::pair<int, int>>> qv(p);
    for(int i=0; i<p; i++) std::cin >> s[i];
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<m; j++) {
            state[i][j] = str[j];
            visited[i][j] = false;
            if(state[i][j] >= '1' && state[i][j] <= '9') {
                visited[i][j] = true;
                qv[state[i][j]-'1'].push({i, j});
            }
        }
    }
    bool expanded = true;
    while(expanded) {
        expanded = false;
        for(int player = 0; player < p; player++) {
            // std::cout << "player #" << player+1 << '\n';
            int dist = -1;
            while(!qv[player].empty() && ++dist < s[player]) {
                int sz = qv[player].size();
                while(sz--) {
                    auto get = qv[player].front(); qv[player].pop();
                    // std::cout << "get = (" << get.first << ", " << get.second << ")\n";
                    for(int d=0; d<4; d++) {
                        std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                        if(pos_check(next) && !visited[next.first][next.second] && state[next.first][next.second] == BLANK) {
                            expanded = true;
                            visited[next.first][next.second] = true;
                            state[next.first][next.second] = state[get.first][get.second];
                            qv[player].push(next);
                            // std::cout << "push (" << next.first << ", " << next.second << ")\n";
                        }
                    }
                }
            }
            // show();
        }
    }
    int cnt[9] = {0, };
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(state[i][j] >= '1' && state[i][j] <= '9') cnt[state[i][j]-'1']++;
        }
    }
    for(int i=0; i<p; i++) {
        std::cout << cnt[i] << (i == p-1 ? '\n' : ' ');
    }
}