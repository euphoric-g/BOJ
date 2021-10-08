#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> pos;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int arr[101][101];

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int min_h = 101, max_h = 0;
    int max_count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> arr[i][j];
            min_h = std::min(min_h, arr[i][j]);
            max_h = std::max(max_h, arr[i][j]);
        }
    }
    for(int height = min_h-1; height <= max_h; height++) {
        // 모든 높이에서 BFS
        bool visit[101][101];
        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visit[i][j] = false;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visit[i][j] && arr[i][j] > height) {
                    // 해당 위치부터 탐색 시작
                    count++;
                    std::queue<pos> q;
                    visit[i][j] = true;
                    q.push(pos(i, j));
                    while(!q.empty()) {
                        pos get = q.front(); q.pop();
                        for(int d=0; d<4; d++) {
                            pos next = pos(get.first + dx[d], get.second + dy[d]);
                            if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < n) {
                                if(!visit[next.first][next.second] && arr[next.first][next.second] > height) {
                                    visit[next.first][next.second] = true;
                                    q.push(next);
                                }
                            }
                        }
                    }
                    max_count = std::max(max_count, count);
                }
            }
        }
    }
    std::cout << max_count << "\n";
    return 0;
}