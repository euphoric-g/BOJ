#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define NOT_MOVE -1
#define DEFAULT -2

class Level {
    public:
    int num;
    int up;
    int down;
    bool visited;
    Level() {}
    Level(int lv) { num = lv; visited = false; }
};

int main() {
    int f, s, g, u, d;
    std::cin >> f >> s >> g >> u >> d;
    std::vector<Level> building;
    for(int i=1; i<=f; i++) {
        Level lv = Level(i);
        lv.up = i+u <= f ? i+u : NOT_MOVE;
        lv.down = i-d >= 1 ? i-d : NOT_MOVE;
        building.push_back(lv);
    }
    std::queue<Level> q;
    building[s-1].visited = true;
    q.push(building[s-1]);
    bool find = false;
    int depth = -1;
    while(!q.empty()) {
        depth++;
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            Level get = q.front(); q.pop();
            if(get.num == g) {
                std::cout << depth << std::endl;
                return 0;
            }
            if(get.up != NOT_MOVE && !building[get.up-1].visited) {
                building[get.up-1].visited = true;
                q.push(building[get.up-1]);
            }
            if(get.down != NOT_MOVE && !building[get.down-1].visited) {
                building[get.down-1].visited = true;
                q.push(building[get.down-1]);
            }
        }
    }
    std::cout << "use the stairs\n";
    return 0;
}