#include <iostream>
#include <queue>
#include <vector>

std::vector<std::pair<int, int>> connected[100001];
bool visited[100001];

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int v;
    std::cin >> v;
    for(int i=0; i<v; i++) {
        int vertex_num;
        std::cin >> vertex_num;
        while(1) {
            int next_vertex, dist;
            std::cin >> next_vertex;
            if(next_vertex == -1) break;
            std::cin >> dist;
            connected[vertex_num].push_back({next_vertex, dist});
        }
    }
    std::queue<std::pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    int max_dist_vertex = -1;
    int max_dist = -1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(max_dist < cur.second) {
            max_dist_vertex = cur.first;
            max_dist = cur.second;
        }
        for(const auto &next : connected[cur.first]) {
            if(!visited[next.first]) {
                q.push({next.first, cur.second + next.second});
                visited[next.first] = true;
            }
        }
    }
    for(int i=0; i<100001; i++) visited[i] = false;
    q.push({max_dist_vertex, 0});
    visited[max_dist_vertex] = true;
    int diameter = 0;
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