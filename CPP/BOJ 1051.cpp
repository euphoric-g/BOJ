#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> array;
    for(int i=0; i<n; i++) {
        std::vector<int> arr;
        for(int j=0; j<m; j++) {
            char num;
            std::cin >> num;
            arr.push_back(num -'0');
        }
        array.push_back(arr);
    }
    int max_size = 0;
    for(int i=0; i<n && n-i > max_size; i++) {
        for(int j=0; j<m && m-j > max_size; j++) {
            // (i, j) 왼쪽 위 모서리
            for(int k = j+max_size; k < m; k++) {
                // (i, k) 오른쪽 위 모서리
                // 변의 길이 (k-j+1)
                // (i+k-j, j) 왼쪽 아래
                // (i+k-j, k) 오른쪽 아래
                if((i+k-j < n) && array[i][j] == array[i][k] && array[i][j] == array[i+k-j][j] && array[i][j] == array[i+k-j][k]) {
                    max_size = std::max(max_size, k-j+1);
                }
            }
        }
    }
    std::cout << max_size * max_size << std::endl;
}