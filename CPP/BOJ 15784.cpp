#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;
    int arr[1001][1001];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> arr[i][j];
        }
    }
    int score = arr[a][b];
    int max_score = 0;
    for(int i=0; i<n; i++) {
        max_score = std::max(max_score, arr[i][b]);
        max_score = std::max(max_score, arr[a][i]);
    }
    std::cout << (max_score > score ? "ANGRY\n" : "HAPPY\n");
}