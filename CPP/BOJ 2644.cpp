#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, s, e, m;
    std::cin >> n >> s >> e >> m;
    bool visited[n+1];
    std::vector<std::vector<int>> vec(n+1);
    for(int i=0; i<=n; i++) visited[i] = false;
    for(int i=0; i<m; i++) {
        int x, y;
        std::cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int dist = -1;
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int sz = q.size();
        dist++;
        while(sz-->0){
            int get = q.front(); q.pop();
            if(get == e) {
                std::cout << dist << '\n';
                return 0;
            }
            for(const auto &next : vec[get]) {
                if(!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}