#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, p, s;
    std::cin >> n >> p >> s;
    while(s--) {
        std::unordered_map<int, int> um;
        int m;
        std::cin >> m;
        while(m--) {
            int chosen;
            std::cin >> chosen;
            um[chosen]++;
        }
        if(um[p] == 0) std::cout << "REMOVE\n";
        else std::cout << "KEEP\n";
    }
}