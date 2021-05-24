#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> m;
    for(int i=1; i<=9; i++) {
        int a;
        std::cin >> a;
        m.push_back(std::pair<int, int>(a, i));
    }
    std::sort(m.begin(), m.end(), std::greater<std::pair<int, int>>());
    std::cout << m[0].first << '\n' << m[0].second << '\n';
    return 0;
}