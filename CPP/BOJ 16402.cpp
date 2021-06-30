#include <iostream>
#include <string>
#include <map>
#include <vector>

#define ROOT (std::string("ROOT_NODE"))
#define PREFIX (std::string("Kingdom of "))
#define PREFIX_SIZE (PREFIX.size())

std::string find_root(std::map<std::string, std::string> &arr, std::string name) {
    if(arr[name] == ROOT) return name;
    return arr[name] = find_root(arr, arr[name]);
}

void _union(std::map<std::string, std::string> &arr, std::string winner, std::string loser) {
    std::string root_winner = find_root(arr, winner);
    std::string root_loser = find_root(arr, loser);
    if(root_winner != root_loser) {
        arr[root_loser] = root_winner;
    } else if(root_winner == loser){
        arr[winner] = ROOT;
        _union(arr, winner, loser);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();
    std::map<std::string, std::string> arr;
    for(int i=0; i<n; i++) {
        std::string name;
        std::getline(std::cin, name);
        auto it = name.find(PREFIX, 0);
        arr[name.substr(it+PREFIX_SIZE, name.size())] = ROOT;
    }
    for(int i=0; i<m; i++) {
        std::string result;
        std::getline(std::cin, result);
        auto it = result.find(PREFIX, 0);
        auto it2 = result.find(',', it);
        std::string kd1 = result.substr(it+PREFIX_SIZE, it2-it-PREFIX_SIZE);
        it = result.find("Kingdom of ", it2);
        it2 = result.find(',', it);
        std::string kd2 = result.substr(it+PREFIX_SIZE, it2-it-PREFIX_SIZE);
        int end = std::stoi(result.substr(it2+1, result.size()));
        #ifdef DEBUG
        std::cout << kd1 << ' ' << kd2 << ' ' << end << '\n';
        #endif
        if(end == 1) {
            _union(arr, kd1, kd2);
        } else {
            _union(arr, kd2, kd1);
        }
    }
    std::vector<std::string> ans;
    for(const auto &item : arr) {
        if(item.second == ROOT) ans.push_back(PREFIX + item.first);
    }
    std::cout << ans.size() << '\n';
    for(const auto &item : ans) {
        std::cout << item << '\n';
    }
    return 0;
}