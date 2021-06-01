#include <iostream>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    int *a = new int[n];
    int *b = new int[m];
    for(int i=0; i<n; i++) std::cin >> a[i];
    for(int i=0; i<m; i++) std::cin >> b[i];
    int pa = 0, pb = 0;
    while(pa < n && pb < m) {
        if(a[pa] <= b[pb]) {
            std::cout << a[pa++] << ' ';
        } else {
            std::cout << b[pb++] << ' ';
        }
    }
    if(pa == n) {
        while(pb < m) std::cout << b[pb++] << ' ';
    } else if(pb == m) {
        while(pa < n) std::cout << a[pa++] << ' ';
    }
    std::cout << '\n';
    return 0;
}