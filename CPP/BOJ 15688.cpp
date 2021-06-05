#include <iostream>
#include <algorithm>

int *arr;

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    arr = new int[n];
    for(int i=0; i<n; i++) std::cin >> arr[i];
    std::sort(arr, arr+n);
    for(int i=0; i<n; i++) std::cout << arr[i] << '\n';
    return 0;
}