#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <queue>
#include <string>


class Point {
    public:
    int num;
    bool checked;
    std::vector<std::pair<int, Point *>> connected;
    Point(){}
    Point(int n) {
        num = n;
        checked = false;
    }
    void connect(int n, Point *dest) {
        connected.push_back(std::pair<int, Point *>(n, dest));
    }
    void clear() { checked = false; }
    void set() { checked = true; }
    void dfs() {
        if(!checked) {
            set();
            std::cout << num << " ";
            for(std::vector<std::pair<int, Point *>>::iterator it = connected.begin(); it != connected.end(); it++) {
                if(!it->second->checked) {
                    it->second->dfs();
                }
            }
        }
    }
    void bfs() {
        if(!checked) {
            std::queue<Point *> q;
            q.push(this);
            while(!q.empty()) {
                int sz = q.size();
                for(int i=0; i<sz; i++) {
                    Point *temp = q.front(); q.pop();
                    std::cout << temp->num << " ";
                    temp->set();
                    for(std::vector<std::pair<int, Point *>>::iterator it = temp->connected.begin(); it != temp->connected.end(); it++) {
                        if(!it->second->checked) {
                            it->second->set();
                            q.push(it->second);
                        }
                    }
                }
            }
        }
    }
    void sort_connection();
};

bool cmp(const std::pair<int, Point *>& a, const std::pair<int, Point *>& b) {
    return a.first < b.first;
}

void Point::sort_connection() {
    std::sort(connected.begin(), connected.end(), cmp);
}

void clear_all(Point p[], int nmemb) {
    for(int i=0; i<nmemb; i++) {
        p[i].clear();
    }
}

int main() {
    int n, m, v;
    std::cin >> n >> m >> v;
    Point p[n];
    clear_all(p, n);
    for(int i=0; i<n; i++) {
        p[i] = Point(i+1);
    }
    for(int i=0; i<m; i++) {
        int from, to;
        std::cin >> from >> to;
        p[from-1].connect(to-1, &p[to-1]);
        p[to-1].connect(from-1, &p[from-1]);
    }
    for(int i=0; i<n; i++) p[i].sort_connection();
    p[v-1].dfs();
    std::cout << std::endl;
    clear_all(p, n);
    p[v-1].bfs();
    std::cout << std::endl;
}