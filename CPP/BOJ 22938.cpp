#include <iostream>

typedef long long ll;

int main() {
    ll x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1;
    std::cin >> x2 >> y2 >> r2;
    ll dist_square = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    ll square_radius_sum = (r1 + r2) * (r1 + r2);
    if(square_radius_sum <= dist_square) {
        // 만나지 않거나 한 점에서 만남
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
}