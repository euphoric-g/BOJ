#include <iostream>
#include <vector>
#include <algorithm>

// #define DEBUG
#define INF 5'0000'0000

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    int map[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++) {
        int from, to, time;
        std::cin >> from >> to >> time;
        map[from-1][to-1] = std::min(time, map[from-1][to-1]);
    }
    for(int i=0; i<n; i++) {
        // i번 도시를 거쳐가는 경로 체크
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                // j번 도시에서 k번 도시로 가는데 i번 도시를 거치는 경우
                map[j][k] = std::min(map[j][k], map[j][i] + map[i][k]);
            }
        }
    }
    int friends;
    std::vector<int> friend_loc;
    std::vector<std::pair<int, int>> candidates;
    std::cin >> friends;
    for(int i=0; i<friends; i++) {
        int where;
        std::cin >> where;
        friend_loc.push_back(where-1);
    }
    #ifdef DEBUG
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cout << (map[i][j] >= INF ? "INF" : std::to_string(map[i][j])) << ' ';
        }
        std::cout << '\n';
    }
    #endif
    for(int i=0; i<n; i++) {
        // 모임 장소가 i번 도시인 경우
        int max_time = -1;
        for(const auto &loc : friend_loc) {
            max_time = std::max(map[loc][i] + map[i][loc], max_time);
        }
        if(max_time >= INF) continue;
        candidates.push_back({i, max_time});
    }
    std::sort(candidates.begin(), candidates.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });
    int min_max_time = candidates[0].second;
    while(candidates.back().second != min_max_time) candidates.pop_back();
    for(const auto &sum : candidates) {
        std::cout << sum.first + 1 << ' ';
    }
    std::cout << '\n';
}