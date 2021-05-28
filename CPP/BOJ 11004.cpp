#include <iostream>
#include <algorithm>

int *arr;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    arr = new int[n];
    for(int i=0; i<n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr+n);
    std::cout << arr[k-1] << '\n';
    return 0;
}