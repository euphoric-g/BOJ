#include <iostream>
#include <algorithm>

int population[21][21];

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, total = 0;
    std::cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            std::cin >> population[i][j];
            total += population[i][j];
        }
    }
    int answer = INT32_MAX;
    for(int x = 2; x <= n-1; x++) {
        for(int y = 2; y <= n-1; y++) {
            for(int d1 = 1; d1 <= y-1; d1++) {
                for(int d2 = 1; d2 <= n-y; d2++) {
                    if(x + d1 + d2 > n) continue;
                    if(y - d1 < 1) continue;
                    if(y + d2 > n) continue;
                    int temp[5] = {0, };
                    auto add = [&temp, &population](int c, int d, int e) {
                        temp[c] += population[d][e];
                    };
                    for(int i=1; i<=n; i++) {
                        for(int j=1; j<=n; j++) {
                            if(i < x && j <= y) add(0, i, j);
                            else if(i >= x && i < x+d1 && j < y-i+x) add(0, i, j);
                            else if(i < x && j > y) add(1, i, j);
                            else if(i >= x && i <= x+d2 && j > y+i-x) add(1, i, j);
                            else if(i >= x+d1 && i <= x+d1+d2 && j < y-d1+i-x-d1) add(2, i, j);
                            else if(i > x+d1+d2 && j < y-d1+d2) add(2, i, j);
                            else if(i > x+d2 && i <= x+d1+d2 && j > y+d2-i+x+d2) add(3, i, j);
                            else if(i > x+d1+d2 && j >= y-d1+d2) add(3, i, j);
                            else add(4, i, j);
                        }
                    }
                    std::sort(temp, temp+5);
                    int val = temp[4] - temp[0];
                    answer = std::min(answer, val);
                }
            }
        }
    }
    std::cout << answer << '\n';
    return 0;
}