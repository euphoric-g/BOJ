#include <iostream>
#include <vector>
#include <queue>

#define NO_PART 0
#define PART_1 1
#define PART_2 2

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int k;
    std::cin >> k;
    auto other = [](const int p) -> int { return p == PART_1 ? PART_2 : PART_1; };
    while(k-->0) {
        int v, e;
        std::cin >> v >> e;
        std::vector<std::vector<int>> arr(v+1);
        int part[v+1];
        bool visited[v+1];
        for(int i=0; i<=v; i++) {
            visited[i] = false;
            part[i] = NO_PART;
        }
        for(int i=0; i<e; i++) {
            int x, y;
            std::cin >> x >> y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for(int i=1; i<=v; i++) {
            if(!visited[i]) {
                visited[i] = true;
                part[i] = PART_1;
                std::queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int get = q.front(); q.pop();
                    for(const auto &item : arr[get]) {
                        if(!visited[item]) {
                            visited[item] = true;
                            part[item] = other(part[get]);
                            q.push(item);
                        }
                    }
                }
            }
        }
        bool valid = true;
        for(int i=1; i<=v; i++) {
            for(const auto &item : arr[i]) {
                if(part[i] == part[item]) valid = false;
            }
        }
        std::cout << (valid ? "YES\n" : "NO\n");
    }
}