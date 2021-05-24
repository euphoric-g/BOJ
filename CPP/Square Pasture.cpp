#include <iostream>

int main() {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int x13min = std::min(x1, x3);
    int x24max = std::max(x2, x4);
    int y13min = std::min(y1, y3);
    int y24max = std::max(y2, y4);
    int width = x24max - x13min;
    int height = y24max - y13min;
    int length = std::max(width, height);
    std::cout << length * length << std::endl;
    return 0;
}