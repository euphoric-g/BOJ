#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<int> arr;
    for(int i=0; i<n; i++) {
        int item;
        std::cin >> item;
        arr.push_back(item);
    }
    std::sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    int stored_left, stored_right;
    int min = INT32_MAX;
    while(left < right) {
        if(abs(arr[left]+arr[right]) < min) {
            min = abs(arr[left]+arr[right]);
            stored_left = arr[left];
            stored_right = arr[right];
        }
        if(arr[left] + arr[right] > 0) {
            right--;
        } else {
            left++;
        }
    }
    std::cout << stored_left << " " << stored_right << '\n';
    return 0;
}