#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        int arr[10];
        for(int i=0; i<10; i++) std::cin >> arr[i];
        std::sort(arr, arr+10);
        std::cout << arr[7] << '\n';
    }
    return 0;
}