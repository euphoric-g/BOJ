#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    ull n, q;
    std::cin >> n >> q;
    std::vector<std::pair<int, ull>> vec;
    for(int i=1; i<=n; i++) {
        ull cost, k, c;
        std::cin >> cost >> k >> c;
        if(k >= q) {
            vec.push_back({i, cost});
        } else {
            ull z = q/k;
            if(z*k == q) z--;
            vec.push_back({i, cost + c*(z*(z+1)/2)});
        }
    }
    std::stable_sort(vec.begin(), vec.end(), [](const std::pair<int, ull> &a, const std::pair<int, ull> &b) -> bool {
        return a.second < b.second;
    });
    std::cout << vec[0].first << ' ' << vec[0].second << '\n';
    return 0;
}