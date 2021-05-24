#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <tuple>

const std::vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
const std::vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int arr[10][10];
int food[10][10];
std::deque<int> pq[10][10];
std::queue<std::tuple<int, int, int>> q;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m, k;
    std::cin >> n >> m >> k;
    auto pos_check = [&n](int nx, int ny) -> bool { return nx >= 0 && nx < n && ny >= 0 && ny < n; };
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> arr[i][j];
            food[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        pq[x-1][y-1].push_back(z);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::sort(pq[i][j].begin(), pq[i][j].end(), std::greater<int>());
        }
    }
    while(k-->0) {
        // 봄
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sz = pq[i][j].size();
                while(sz-->0) {
                    // 양분 확인하고 임시 큐 q에 저장
                    int get = pq[i][j].front(); pq[i][j].pop_front();
                    // printf("봄, (%d, %d), 나무 나이 : %d, 양분 : %d\n", i, j, get, food[i][j]);
                    if(get > food[i][j]) {
                        q.push(std::make_tuple(i, j, get));
                    } else {
                        food[i][j] -= get;
                        pq[i][j].push_back(get+1);
                    }
                }
            }
        }
        // 여름
        while(!q.empty()) {
            int x, y, age;
            std::tie(x, y, age) = q.front(); q.pop();
            food[x][y] += age/2;
        }
        // 가을
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int sz = pq[i][j].size();
                while(sz-->0) {
                    int get = pq[i][j].front(); pq[i][j].pop_front();
                    // printf("가을, (%d, %d), 나무 나이 : %d, 양분 : %d\n", i, j, get, food[i][j]);
                    if(get > 0 && get % 5 == 0) {
                        for(int d=0; d<8; d++) {
                            int nx = i+dx[d], ny = j+dy[d];
                            if(pos_check(nx, ny)) {
                                pq[nx][ny].push_front(1);
                            }
                        }
                    }
                    pq[i][j].push_back(get);
                }
            }
        }
        // 겨울
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                food[i][j] += arr[i][j];
                // printf("겨울, (%d, %d) : %d -> %d\n", i, j, food[i][j]-arr[i][j], food[i][j]);
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cnt += pq[i][j].size();
        }
    }
    std::cout << cnt << '\n';
    return 0;
}