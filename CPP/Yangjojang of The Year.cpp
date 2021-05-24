#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compare(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
    return a.second > b.second;
}

int main() {
    int t;
    std::cin >> t;
    for(int i=0; i<t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::pair<std::string, int>> vec;
        for(int j=0; j<n; j++) {
            std::string strin;
            int am;
            std::cin >> strin >> am;
            vec.push_back(std::pair<std::string, int>(strin, am));
        }
        std::sort(vec.begin(), vec.end(), compare);
        std::cout << vec[0].first << std::endl;
    }
    return 0;
}