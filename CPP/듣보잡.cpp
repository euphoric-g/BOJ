#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, int> map;
    int n, m;
    std::cin >> n >> m;
    for(int i=0; i<n; i++) {
        std::string in;
        std::cin >> in;
        map[in]++;
    }
    for(int i=0; i<m; i++) {
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
    std::cout << dbj.size() << std::endl;
    for(const auto &name : dbj) {
        std::cout << name << std::endl;
    }
    return 0;
}