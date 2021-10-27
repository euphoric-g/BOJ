#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// N, E, S, W
const int N = 0, E = 1, S = 2, W = 3;
pair<int, int> loc = {0, 0};
int dir = E;
int u = 1, d = 6, l = 4, r = 3, f = 5, b = 2;
int total_score = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    auto poscheck = [&n, &m](pair<int, int> location) -> bool {
        location.first >= 0 && location.first < n && location.second >= 0 && location.second < m;
    };
    auto rev_dir = []() { dir = (dir + 2) % 4; };
    auto CW_dir = []() { dir = (dir + 1) % 4; };
    auto CCW_dir = []() { dir = (dir + 3) % 4; };
    auto roll_front = []() {
        int temp = u;
        u = b; b = d; d = f; f = temp;
    };
    auto roll_back = []() {
        int temp = u;
        u = f; f = d; d = b; b = temp;
    };
    auto roll_left = []() {
        int temp = u;
        u = r; r = d; d = l; l = temp;
    };
    auto roll_right = []() {
        int temp = u;
        u = l; l = d; d = r; r = temp;
    };
    vector<vector<int>> map(n);
    vector<vector<bool>> visited(n);
    vector<vector<int>> score(n);
    for(int i=0; i<n; i++) {
        map[i] = vector<int>(m);
        visited[i] = vector<bool>(m, false);
        score[i] = vector<int>(m, 0);
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j]) continue;
            queue<pair<int, int>> q;
            queue<pair<int, int>> store;
            q.push({i, j});
            visited[i][j] = true;
            while(!q.empty()) {
                auto get = q.front();
                store.push(q.front()); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = get.first + dx[d], ny = get.second + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!visited[nx][ny] && (map[get.first][get.second] == map[nx][ny])) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            int connected_cnt = store.size();
            while(!store.empty()) {
                auto get = store.front(); store.pop();
                score[get.first][get.second] = connected_cnt;
            }
        }
    }
    while(k--) {
        int nx = loc.first + dx[dir], ny = loc.second + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) rev_dir();
        nx = loc.first + dx[dir], ny = loc.second + dy[dir];
        loc = {nx, ny};
        /*
        string str[] = {"북쪽", "동쪽", "남쪽", "서쪽"};
        cout << str[dir] << "방향으로 이동하여 현재 위치는 {" << nx << ", " << ny << "} 입니다.\n";
        */
        switch(dir) {
            case N :
            roll_back();
            break;
            case E :
            roll_right();
            break;
            case S :
            roll_front();
            break;
            case W :
            roll_left();
            break;
        }
        total_score += score[loc.first][loc.second] * map[loc.first][loc.second];
        if(d > map[loc.first][loc.second]) CW_dir();
        else if(d < map[loc.first][loc.second]) CCW_dir();
        /*
        cout << "주사위 방향은 " << str[dir] << "이며, 전개도는 아래와 같습니다.\n";
        cout << "현재 점수는 " << total_score << "입니다.\n";
        cout << "\t" << b << "\n" << l << "\t" << u << "\t" << r << "\n\t" << f << "\n\t" << d << '\n';
        */
    }
    cout << total_score << '\n';
}