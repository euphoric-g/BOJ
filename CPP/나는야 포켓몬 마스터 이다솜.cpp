#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n, m;
    fscanf(stdin, "%d %d", &n, &m);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::map<std::string, int> map;
    std::vector<std::string> names;
    for(int i=1; i<=n; i++) {
        std::string name;
        std::cin >> name;
        map.insert(std::pair<std::string, int>(name, i));
        names.push_back(name);
    }
    for(int i=0; i<m; i++) {
        std::string input;
        std::cin >> input;
        try {
            // number
            int num = stoi(input);
            std::cout << names[num-1] << "\n";
        } catch (std::exception &e) {
            // string
            auto it = map.find(input);
            std::cout << it->second << "\n";
        }
    }
}