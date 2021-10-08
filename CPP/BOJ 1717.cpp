#include <iostream>
#include <vector>

int *arr;

int find_root(int n) {
    if(arr[n] == n) return n;
    return arr[n] = find_root(arr[n]);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    arr = new int[n+1];
    for(int i=0; i<=n; i++) {
        arr[i] = i;
    }
    for(int i=0; i<m; i++) {
        int op, a, b;
        std::cin >> op >> a >> b;
        int root_a = find_root(a);
        int root_b = find_root(b);
        if(op == 0) {
            if(root_a != root_b) arr[root_b] = a;
        } else {
            std::cout << (root_a == root_b ? "YES\n" : "NO\n");
        }
    }
    delete[] arr;
    return 0;
}