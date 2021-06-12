#include <iostream>

int main() {
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    int cost = 0;
    int small = std::min(x, y);
    if(a+b>=2*c) {
        cost += 2*c*small;
    } else {
        cost += (a+b)*small;
    }
    x -= small;
    y -= small;
    int kind;
    if(x != 0 && y == 0) kind = 0;
    else if(x == 0 && y != 0) kind = 1;
    else {
        std::cout << cost << '\n';
        return 0;
    }
    if(kind == 0) {
        cost += std::min(a*x, 2*c*x);
    } else {
        cost += std::min(b*y, 2*c*y);
    }
    std::cout << cost << '\n';
    return 0;
}