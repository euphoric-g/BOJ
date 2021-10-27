#include <iostream>
#include <string>
#include <queue>

using namespace std;

int visited[50][50][1 << 6];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    queue<pair<pair<int, int>, int>> q;
    auto pos_check = [&n, &m](pair<int, int> &loc) -> bool {
        return loc.first >= 0 && loc.first < n && loc.second >= 0 && loc.second < m;
    };
    auto is_door = [&map](pair<int, int> &loc) -> bool {
        return map[loc.first][loc.second] >= 'A' && map[loc.first][loc.second] <= 'F';
    };
    auto is_key = [&map](pair<int, int> &loc) -> bool {
        return map[loc.first][loc.second] >= 'a' && map[loc.first][loc.second] <= 'f';
    };
    auto have_key = [&map](int bit, pair<int, int> &loc) -> bool {
        return bit & (1 << (map[loc.first][loc.second] - 'A'));
    };
    for(int i=0; i<n; i++) {
        cin >> map[i];
        for(int j=0; j<m; j++) {
            if(map[i][j] == '0') {
                q.push({{i, j}, 0});
                visited[i][j][0] = 1;
            }
        }
    }
    int time = 0;
    while(!q.empty()) {
        int sz = q.size();
        time++;
        while(sz--) {
            auto cur_loc = q.front().first;
            auto bitmask = q.front().second; q.pop();
            if(map[cur_loc.first][cur_loc.second] == '1') {
                cout << time-1 << '\n';
                return 0;
            }
            for(int i=0; i<4; i++) {
                pair<int, int> next = {cur_loc.first + dx[i], cur_loc.second + dy[i]};
                if(!pos_check(next)) continue;
                if(map[next.first][next.second] != '#' && (!is_door(next) || (is_door(next) && have_key(bitmask, next)))) {
                    auto next_bm = bitmask;
                    if(is_key(next)) next_bm |= (1 << (map[next.first][next.second] - 'a'));
                    if(!visited[next.first][next.second][next_bm]) {
                        visited[next.first][next.second][next_bm] = time;
                        q.push({next, next_bm});
                    }
                }
            }
        }
    }
    cout << "-1\n";
}