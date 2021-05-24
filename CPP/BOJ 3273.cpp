#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, x;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    for(int i=0; i<n; i++) std::cin >> arr[i];
    std::cin >> x;
    std::sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    int cnt = 0;
    while(left < right) {
        if(arr[left] + arr[right] > x) {
            right--;
        } else {
            if(arr[left] + arr[right] == x) cnt++;
            left++;
        }
    }
    std::cout << cnt << '\n';
    return 0;
}