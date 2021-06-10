#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<std::string> list;
        for(int i=0; i<n; i++) {
            std::string number;
            std::cin >> number;
            list.push_back(number);
        }
        std::sort(list.begin(), list.end());
        bool flag = true;
        for(int i=0; i<n-1 && flag; i++) if(list[i+1].substr(0, list[i].size()) == list[i]) flag = false;
        if(flag) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}