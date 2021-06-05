#include <iostream>
#include <vector>
#include <queue>

#define ENTRANCE 1

typedef long long ll;

class Room {
    public:
    bool visited;
    ll dist;
    std::vector<std::pair<int, ll>> connected;
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<Room> rooms(n+1);
    for(int i=1; i<=n; i++) {
        rooms[i].dist = INT64_MAX;
        rooms[i].visited = false;
    }
    for(int i=0; i<n-1; i++) {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        rooms[a].connected.push_back({b, c});
        rooms[b].connected.push_back({a, c});
    }
    rooms[ENTRANCE].dist = 0;
    rooms[ENTRANCE].visited = true;
    std::queue<int> q;
    q.push(ENTRANCE);
    while(!q.empty()) {
        auto get = rooms[q.front()]; q.pop();
        for(const auto &item : get.connected) {
            if(!rooms[item.first].visited && rooms[item.first].dist == INT64_MAX) {
                rooms[item.first].visited = true;
                rooms[item.first].dist = get.dist + item.second;
                q.push(item.first);
            }
        }
    }
    ll max_dist = 0;
    for(int i=1; i<=n; i++) {
        max_dist = std::max(max_dist, rooms[i].dist);
    }
    std::cout << max_dist << '\n';
    return 0;
}