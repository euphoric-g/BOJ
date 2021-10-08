#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> circle;
    std::vector<int> arr;
    int n, k;
    std::cin >> n >> k;
    for(int i=0; i<n; i++) circle.push_back(i+1);
    int cursor = k-1;
    // 3 6 2 7 5 1 4

    // 1 2 3 4 5 6 7
    // 1 2   4 5 6 7 >> 1 2 4 5 6 7
    // 1 2   4 5   7
    // 1     4 5   7
    while(1) {
        arr.push_back(circle[cursor]);
        circle.erase(circle.begin() + cursor);
        if(circle.empty()) break;
        cursor -= 1;
        cursor = (cursor + k) % circle.size();
    }
    std::cout << "<";
    int sz = arr.size();
    for(int i=0; i<sz; i++) {
        if(i != sz-1) std::cout << arr[i] << ", ";
        else std::cout << arr[i];
    }
    std::cout << ">" << std::endl;
    return 0;
}