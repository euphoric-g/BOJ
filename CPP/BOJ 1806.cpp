#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, s;
    std::cin >> n >> s;
    std::vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        std::cin >> arr[i];
    }
    int min_len = INT32_MAX;
    int left = 0, right = 0, sum = arr[0];
    while(left <= right && left < n && right < n) {
        if(sum < s) {
            sum += arr[++right];
        } else {
            min_len = std::min(min_len, right - left + 1);
            sum -= arr[left++];
        }
    }
    std::cout << (min_len == INT32_MAX ? 0 : min_len) << '\n';
    return 0;
}