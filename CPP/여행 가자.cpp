#include <iostream>

int cities[201];

int find_root(int n) {
    if(cities[n] == n) return n;
    return find_root(cities[n]);
}

void merge(int a, int b) {
    int ra = find_root(a);
    int rb = find_root(b);
    if(ra != rb) {
        cities[rb] = ra;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    for(int i=1; i<=n; i++) cities[i] = i;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int link;
            std::cin >> link;
            if(i != j && link == 1) {
                merge(i, j);
            }
        }
    }
    bool flag = true;
    int root = -1;
    for(int i=0; i<m; i++) {
        int travel;
        std::cin >> travel;
        if(root == -1) {
            root = find_root(travel);
            continue;
        }
        if(find_root(travel) != root) flag = false;
    }
    std::cout << (flag ? "YES\n" : "NO\n");
    return 0;
}