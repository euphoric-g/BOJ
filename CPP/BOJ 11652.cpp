#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::unordered_map<long long, int> cards;
    for(int i=0; i<n; i++) {
        long long input;
        std::cin >> input;
        cards[input]++;
    }
    std::vector<std::pair<long long, int>> arr;
    for(const auto &elem : cards) {
        arr.push_back(elem);
    }
    std::sort(arr.begin(), arr.end(), [](const std::pair<long long, int> &a, const std::pair<long long, int> &b) -> bool {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    std::cout << arr[0].first << '\n';
    return 0;
}