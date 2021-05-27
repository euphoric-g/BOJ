#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define BLANK 0
#define PAPER 1

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    int m, n, k;
    bool visited[101][101];
    int arr[101][101];
    std::cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = false;
            arr[i][j] = BLANK;
        }
    }
    for(int i=0; i<k; i++) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<x2; i++) {
            for(int j=y1; j<y2; j++) {
                arr[j][i] = PAPER;
            }
        }
    }
    std::vector<int> area;
    auto pos_check = [&n, &m](const std::pair<int, int> &pos) -> bool {
        return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m;
    };
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {    
            if(!visited[i][j] && arr[i][j] == BLANK) {
                std::queue<std::pair<int, int>> q;
                visited[i][j] = true;
                q.push({i, j});
                int cnt = 0;
                while(!q.empty()) {
                    auto get = q.front(); q.pop();
                    cnt++;
                    for(int d=0; d<4; d++) {
                        std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                        if(pos_check(next) && !visited[next.first][next.second] && arr[next.first][next.second] == BLANK) {
                            visited[next.first][next.second] = true;
                            q.push(next);
                        }
                    }
                }
                area.push_back(cnt);
            }
        }
    }
    std::sort(area.begin(), area.end());
    std::cout << area.size() << '\n';
    for(const auto &item : area) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
    return 0;
}