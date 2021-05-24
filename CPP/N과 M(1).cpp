#include <iostream>
#include <algorithm>

int arr[8] = {0, };
int level = 0;
int n, m;

int backtracking() {
    int cnt[8] = {0, };
    for(int i=0; i<level; i++) {
        if(++cnt[arr[i]] > 1) return -1;
    }
    if(level == m) {
        for(int i=0; i<m; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        return 0;
    } else {
        for(int i=1; i<=n; i++) {
            arr[level++] = i;
            backtracking();
            level--;
        }
        return 0;
    }
}

int main() {
    std::cin >> n >> m;
    backtracking();
    return 0;
}