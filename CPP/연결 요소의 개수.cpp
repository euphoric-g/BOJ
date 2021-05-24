#include <iostream>
#include <algorithm>
#include <vector>

class Point {
    public:
    bool checked;
    std::vector<Point *> connected;
    Point(){ checked = false; }
    void check() {
        checked = true;
        for(auto &ptr : connected) {
            if(!ptr->checked) ptr->check();
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Point> points;
    for(int i=0; i<n; i++) {
        points.push_back(Point());
    }
    for(int i=0; i<m; i++) {
        int u, v;
        std::cin >> u >> v;
        points[u-1].connected.push_back(&points[v-1]);
        points[v-1].connected.push_back(&points[u-1]);
    }
    int cnt = 0;
    for(auto &element : points) {
        if(!element.checked) {
            cnt++;
            element.check();
        }
    }
    std::cout << cnt << std::endl;
}