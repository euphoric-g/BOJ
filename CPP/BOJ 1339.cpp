#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

std::map<char, int> digit;

int main() {
    int n;
    std::cin >> n;
    while(n-->0) {
        std::string sin;
        std::cin >> sin;
        int cnt = 0;
        while(!sin.empty()) {
            digit[sin.back()] += (int)pow(10, cnt++);
            sin.pop_back();
        }
    }
    int des = 9;
    int answer = 0;
    std::vector<std::pair<char, int>> vec;
    for(const auto &item : digit) vec.push_back({item.first, item.second});
    std::sort(vec.begin(), vec.end(), [](const std::pair<char, int>&a, const std::pair<char, int>&b) -> bool {
        return a.second > b.second;
    });
    for(const auto &item : vec) {
        answer += item.second * des--;
    }
    std::cout << answer << '\n';
}