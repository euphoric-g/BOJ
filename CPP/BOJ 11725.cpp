#include <iostream>
#include <queue>
#include <vector>

#define NO_PARENT 0

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    bool visited[n+1];
    std::vector<std::vector<int>> arr(n+1);
    std::vector<int> parent(n+1, NO_PARENT);
    for(int i=0; i<=n; i++) visited[i] = false;
    for(int i=0; i<n-1; i++) {
        int x, y;
        std::cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int get = q.front(); q.pop();
        for(const auto &child : arr[get]) {
            if(!visited[child] && parent[child] == NO_PARENT) {
                visited[child] = true;
                parent[child] = get;
                q.push(child);
            }
        }
    }
    for(int i=2; i<=n; i++) {
        std::cout << parent[i] << '\n';
    }
    return 0;
}