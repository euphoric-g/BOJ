#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::unordered_map<int, int> dict;
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        int get;
        std::cin >> get;
        dict[get]++;
    }
    std::vector<int> arr;
    for(const auto &elem : dict) {
        arr.push_back(elem.first);
    }
    std::sort(arr.begin(), arr.end());
    for(const auto &elem : arr) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    return 0;
}