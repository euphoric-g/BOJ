#include <iostream>
#include <string>
#include <vector>

int n;
char arr[51][51];

int max_count() {
    int ret = 0;
    for(int i=0; i<n; i++) {
        // 오른쪽
        int temp = -1;
        char cur = 'A';
        for(int j=0; j<n; j++) {
            if(cur != arr[i][j]) {
                cur = arr[i][j];
                temp = 1;
            } else {
                ret = std::max(ret, ++temp);
            }
        }
        // 아래
        temp = -1, cur = 'A';
        for(int j=0; j<n; j++) {
            if(cur != arr[j][i]) {
                cur = arr[j][i];
                temp = 1;
            } else {
                ret = std::max(ret, ++temp);
            }
        }
    }
    return ret;
}

int main() {
    std::cin >> n;
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<n; j++) {
            arr[i][j] = str[j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i+1 < n && arr[i][j] != arr[i+1][j]) {
                // 아래와 교환
                std::swap(arr[i][j], arr[i+1][j]);
                ans = std::max(ans, max_count());
                std::swap(arr[i][j], arr[i+1][j]);
            }
            if(j+1 < n && arr[i][j] != arr[i][j+1]) {
                // 오른쪽과 교환
                std::swap(arr[i][j], arr[i][j+1]);
                ans = std::max(ans, max_count());
                std::swap(arr[i][j], arr[i][j+1]);
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}