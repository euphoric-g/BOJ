#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) std::cin >> arr[i];
    std::sort(arr, arr+n, std::greater<int>());
    for(int i=0; i<n; i++) std::cout << arr[i] << '\n';
    return 0;
}