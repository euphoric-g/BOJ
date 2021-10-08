#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<std::string, std::string> um;
    for(int i=0; i<n; i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        um[s1] = s2;
    }
    for(int i=0; i<m; i++) {
        std::string s1;
        std::cin >> s1;
        std::cout << um[s1] << '\n';
    }
}