#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr(9, 0);
    int sum = -100;
    for(int i=0; i<9; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    int f1, f2;
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++) {
            if(arr[i] + arr[j] == sum) {
                f1 = i, f2 = j;
            }
        }
    }
    for(int i=0; i<9; i++) {
        if(i != f1 && i != f2) {
            std::cout << arr[i] << '\n';
        }
    }
    return 0;
}