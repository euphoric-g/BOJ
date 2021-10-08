#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int main() {
    int n;
    int prev = -1;
    std::cin >> n;
    std::vector<int> arr;
    int *result = new int[n];
    for(int i=0; i<n; i++) {
        int s;
        std::cin >> s;
        arr.push_back(s);
        result[i] = -1;
    }
    std::vector<int> stack;
    int target = 1;
    stack.push_back(0);
    while(!stack.empty() && target < n) {
        while(!stack.empty() && arr[stack.back()] < arr[target]) {
            result[stack.back()] = arr[target];
            stack.pop_back();
        }
        stack.push_back(target);
        target++;
    }
    for(int i=0; i<n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}