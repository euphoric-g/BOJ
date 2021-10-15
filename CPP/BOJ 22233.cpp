#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<std::string, int> keywords;
    for(int i=0; i<n; i++) {
        std::string keyword;
        std::cin >> keyword;
        keywords[keyword] = 1;
    }
    for(int i=0; i<m; i++) {
        std::string used;
        std::cin >> used;
        auto sep = used.find(',', 0);
        while(sep != std::string::npos) {
            std::string parsed = used.substr(0, sep);
            if(--keywords[parsed] <= 0) keywords.erase(parsed);
            used = used.substr(sep+1, used.size());
            sep = used.find(',', 0);
        }
        if(--keywords[used] <= 0) keywords.erase(used);
        std::cout << keywords.size() << '\n';
    }
}