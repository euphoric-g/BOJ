#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    std::unordered_map<std::string, int> map;
    int n, m;
    std::cin >> n >> m;
    for(int i=0; i<n+m; i++) {
        std::string in;
        std::cin >> in;
        map[in]++;
    }
    std::vector<std::string> dbj;
    for(const auto & name : map) {
        if(name.second == 2) {
            dbj.push_back(name.first);
        }
    }
    std::sort(dbj.begin(), dbj.end());
    std::cout << dbj.size() << '\n';
    for(const auto &name : dbj) {
        std::cout << name << '\n';
    }
    return 0;
}