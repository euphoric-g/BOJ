#include <iostream>
#include <queue>
#include <vector>

std::vector<std::pair<int, int>> connected[10001];
bool visited[10001];

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        connected[a].push_back({b, c});
        connected[b].push_back({a, c});
    }
    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    std::pair<int, int> max_dist = {-1, -1};
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(max_dist.second < cur.second) {
            max_dist = cur;
        }
        for(const auto &next : connected[cur.first]) {
            if(!visited[next.first]) {
                q.push({next.first, cur.second + next.second});
                visited[next.first] = true;
            }
        }
    }
    for(int i=0; i<10001; i++) visited[i] = false;
    int diameter = 0;
    q.push({max_dist.first, 0});
    visited[max_dist.first] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        diameter = std::max(diameter, cur.second);
        for(const auto &next : connected[cur.first]) {
            if(!visited[next.first]) {
                q.push({next.first, cur.second + next.second});
                visited[next.first] = true;
            }
        }
    }
    std::cout << diameter << '\n';
}