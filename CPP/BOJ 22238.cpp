#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> hps;
    std::pair<int, int> dir;
    for(int i=0; i<n; i++) {
        int x, y, hp;
        std::cin >> x >> y >> hp;
        hps.push_back(hp);
        if(i==0) {
            int xy_gcd = gcd(abs(x), abs(y));
            x /= xy_gcd, y /= xy_gcd;
            dir = {x, y};
        }
    }
    std::sort(hps.begin(), hps.end());
    int dmg_sum = 0;
    auto sep = hps.begin();
    for(int i=0; i<m; i++) {
        int x, y, dmg;
        std::cin >> x >> y >> dmg;
        int xy_gcd = gcd(abs(x), abs(y));
        x /= xy_gcd, y /= xy_gcd;
        if(dir != std::pair<int, int>(x, y)) {
            std::cout << (int)(hps.end() - sep) << '\n';
            continue;
        }
        dmg_sum += dmg;
        sep = std::upper_bound(hps.begin(), hps.end(), dmg_sum);
        std::cout << (int)(hps.end() - sep) << '\n';
    }
}