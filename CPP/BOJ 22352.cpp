#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int from = 0, to = 1, cmp = 2;
const std::pair<int, int> INIT = std::pair<int, int>(-1, -1);

int main() {
    int n, m;
    std::cin >> n >> m;
    int data[3][31][31];
    for(int i=0; i<2; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                std::cin >> data[i][j][k];
            }
        }
    }
    std::pair<int, int> start = INIT;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(data[from][i][j] == data[to][i][j]) data[cmp][i][j] = 1;
            else {
                data[cmp][i][j] = 0;
                start = std::make_pair(i, j);
            }
        }
    }
    if(start == INIT) {
        std::cout << "YES\n";
        return 0;
    }
}