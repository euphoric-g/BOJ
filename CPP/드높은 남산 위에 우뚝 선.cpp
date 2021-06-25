#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) std::cin >> arr[i];
    if(n==1) {
        std::cout << "YES\n";
        return 0;
    }
    bool mountain = true;
    bool up = true;
    for(int i=1; i<n && mountain; i++) {
        if(arr[i] > arr[i-1] && !up) {
            mountain = false;
        }
        if(arr[i] < arr[i-1] && up) {
            up = false;
        }
        if(arr[i] == arr[i-1]) {
            mountain = false;
        }
    }
    if(mountain) {
        std::cout << "YES\n";
    } else std::cout << "NO\n";
}