#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::map<std::string, int> record;
    for(int i=0; i<n; i++) {
        std::string name, type;
        std::cin >> name >> type;
        if(type == "enter") {
            record[name]++;
        } else {
            record[name]--;
        }
    }
    std::vector<std::string> vec;
    for(const auto &item : record) {
        if(item.second > 0) {
            vec.push_back(item.first);
        }
    }
    for(auto it = vec.rbegin(); it != vec.rend(); it++) {
        std::cout << *it << '\n';
    }
    return 0;
}