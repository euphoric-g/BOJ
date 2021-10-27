#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
// R, L, U, D
const int R = 0, L = 1, U = 2, D = 3;
int cw[] = {3, 2, 0, 1};
int ccw[] = {2, 3, 1, 0};
int rev[] = {1, 0, 3, 2};
const int wr = 1, wl = 2, wu = 4, wd = 8;
int wbit[] = {wr, wl, wu, wd};
pair<int, int> uv[] = {{dx[0], dy[0]}, {dx[1], dy[1]}, {dx[2], dy[2]}, {dx[3], dy[3]}};
int r, c, k, w;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) { return make_pair(a.first+b.first, a.second+b.second); }
vector<vector<int>> map, wall;
vector<pair<int, int>> checklist;
vector<pair<pair<int, int>, int>> heater;
vector<vector<bool>> wind_visited;

bool poscheck(int nx, int ny) { return nx >= 0 && nx < r && ny >= 0 && ny < c; }
bool poscheck(pair<int, int> loc) { return poscheck(loc.first, loc.second); }

void wind_subfn(int x, int y, int dir, int deg) {
    map[x][y] += deg;
    if(deg <= 1) return;
    pair<int, int> fl = make_pair(x, y) + uv[dir] + uv[ccw[dir]];
    pair<int, int> forward = make_pair(x, y) + uv[dir];
    pair<int, int> fr = make_pair(x, y) + uv[dir] + uv[cw[dir]];
    if(poscheck(fl)) {
        if(((wall[x][y] & wbit[ccw[dir]]) == 0) && ((wall[fl.first][fl.second] & wbit[rev[dir]]) == 0)) {
            if(!wind_visited[fl.first][fl.second]) {
                wind_visited[fl.first][fl.second] = true;
                wind_subfn(fl.first, fl.second, dir, deg-1);
            }
        }
    }
    if(poscheck(forward)) {
        if((wall[x][y] & wbit[dir]) == 0) {
            if(!wind_visited[forward.first][forward.second]) {
                wind_visited[forward.first][forward.second] = true;
                wind_subfn(forward.first, forward.second, dir, deg-1);
            }
        }
    }
    if(poscheck(fr)) {
        if(((wall[x][y] & wbit[cw[dir]]) == 0) && ((wall[fr.first][fr.second] & wbit[rev[dir]]) == 0)) {
            if(!wind_visited[fr.first][fr.second]) {
                wind_visited[fr.first][fr.second] = true;
                wind_subfn(fr.first, fr.second, dir, deg-1);
            }
        }
    }
}

void wind() {
    for(int i=0; i<heater.size(); i++) {
        wind_visited = vector<vector<bool>>(r, vector<bool>(c, false));
        int dir = heater[i].second;
        wind_subfn(heater[i].first.first + dx[dir], heater[i].first.second + dy[dir], dir, 5);
    }
}

void adjust() {
    vector<vector<int>> temp(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            for(int d=0; d<4; d++) {
                int nx = i + dx[d], ny = j + dy[d];
                if(!poscheck(nx, ny)) continue;
                if(map[i][j] <= map[nx][ny]) continue;
                if(wall[i][j] & wbit[d]) continue;
                int diff = (map[i][j] - map[nx][ny])/4;
                temp[i][j] -= diff;
                temp[nx][ny] += diff;
            }
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            map[i][j] += temp[i][j];
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> r >> c >> k;
    map = vector<vector<int>>(r, vector<int>(c, 0));
    wall = vector<vector<int>>(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
            if(map[i][j] == 5) checklist.push_back({i, j});
            else if(map[i][j] != 0) heater.push_back({{i, j}, map[i][j]-1});
            map[i][j] = 0;
        }
    }
    cin >> w;
    for(int i=0; i<w; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        --x, --y;
        if(t) {
            wall[x][y] |= wbit[R];
            if(y+1 < c) wall[x][y+1] |= wbit[L];
        } else {
            if(x-1 >= 0) wall[x-1][y] |= wbit[D];
            wall[x][y] |= wbit[U];
        }
    }
    auto debug = [](string txt) {
        cout << txt << '\n';
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    };
    int chocolate = 0;
    while(chocolate < 101) {
        // 온풍기에서 바람
        // debug("시작");
        wind();
        // debug("바람 분 뒤");
        // 온도 조절
        adjust();
        // debug("온도 조절 후");
        // 바깥쪽 칸 온도 감소
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i != 0 && i != r-1 && j != 0 && j != c-1) continue;
                if(--map[i][j] < 0) map[i][j] = 0;
            }
        }
        // debug("온도 감소 후");
        // 초콜릿을 하나 먹는다
        ++chocolate;
        // 검사
        bool check_good = true;
        for(int i=0; i<checklist.size() && check_good; i++) {
            if(map[checklist[i].first][checklist[i].second] < k) check_good = false;
        }
        if(check_good) break;
    }
    cout << chocolate << '\n';
}