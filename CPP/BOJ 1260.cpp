#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>

bool visited[1001];
std::vector<int> connected[1001];
std::vector<int> dfs_list;
std::vector<int> bfs_list;

void dfs(int cur) {
    dfs_list.push_back(cur);
    for(const auto &next : connected[cur]) {
        if(!visited[next]) {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {
    std::fstream fin("input.txt", std::ios::in);
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m, v;
    std::fin >> n >> m >> v;
    while(m--) {
        int a, b;
        std::fin >> a >> b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }
    for(int i=1; i<=n; i++) std::sort(connected[i].begin(), connected[i].end());
    visited[v] = true;
    dfs(v);
    for(int i=0; i<=n; i++) visited[i] = false;
    std::queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()) {
        int get = q.front(); q.pop();
        bfs_list.push_back(get);
        for(const auto &next : connected[get]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    for(const auto &item : dfs_list) std::cout << item << ' ';
    std::cout << '\n';
    for(const auto &item : bfs_list) std::cout << item << ' ';
    std::cout << '\n';
    return 0;
}