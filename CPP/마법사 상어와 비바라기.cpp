#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define LEFT 1
#define UPPER_LEFT 2
#define UP 3
#define UPPER_RIGHT 4
#define RIGHT 5
#define LOWER_RIGHT 6
#define DOWN 7
#define LOWER_LEFT 8

const int xdiff[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int ydiff[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

class Pos {
    public:
    int x, y;
    Pos() {}
    Pos(int a, int b) { x = a; y = b; }
};

class Cell {
    public:
    Pos p;
    int basket;
    Cell() {}
    Cell(Pos cur) { p = cur; }
};

class Cloud {
    public:
    Pos p;
    Cloud() {}
    Cloud(Pos cur) { p = cur; }
};

class Field {
    public:
    Cell grid[51][51];
    std::queue<Cloud> clouds;
    std::queue<std::pair<int, int>> clouds_data;
    int size;
    Field() {
        int m;
        std::cin >> size >> m;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                int arc_in;
                std::cin >> arc_in;
                grid[i][j] = Cell(Pos(i, j));
                grid[i][j].basket = arc_in;
            }
        }
        for(int i=0; i<m; i++) {
            int di, si;
            std::cin >> di >> si;
            clouds_data.push(std::pair<int, int>(di, si));
        }
        for(int i=size-2; i<size; i++) {
            for(int j=0; j<2; j++) {
                clouds.push(Cloud(Pos(i, j)));
            }
        }
    }
    void move_clouds() {
        std::pair<int, int> data = clouds_data.front(); clouds_data.pop();
        int sz = clouds.size();
        for(int z=0; z<sz; z++) {
            Cloud get = clouds.front(); clouds.pop();
            get.p.x += xdiff[data.first] * data.second + 50 * size;
            get.p.y += ydiff[data.first] * data.second + 50 * size;
            get.p.x %= size;
            get.p.y %= size;
            clouds.push(get);
        }
    }
    void rainfall_and_spell() {
        std::queue<Pos> increases;
        bool check[51][51];
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                check[i][j] = true;
            }
        }
        while(!clouds.empty()) {
            Cloud get = clouds.front(); clouds.pop();
            grid[get.p.x][get.p.y].basket++;
            check[get.p.x][get.p.y] = false;
            increases.push(Pos(get.p.x, get.p.y));
        }
        while(!increases.empty()) {
            Pos cur = increases.front(); increases.pop();
            for(int z = 2; z <= 8; z += 2) {
                Pos next = Pos(cur.x + xdiff[z], cur.y + ydiff[z]);
                if(next.x >= 0 && next.x < size && next.y >= 0 && next.y < size && grid[next.x][next.y].basket > 0) {
                    grid[cur.x][cur.y].basket++;
                }
            }
        }
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(check[i][j] && grid[i][j].basket >= 2) {
                    grid[i][j].basket -= 2;
                    clouds.push(Cloud(Pos(i, j)));
                }
            }
        }
    }
    void work() {
        while(!clouds_data.empty()) {
            move_clouds();
            rainfall_and_spell();
        }
        int total = 0;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                total += grid[i][j].basket;
            }
        }
        std::cout << total << std::endl;
    }
};

int main() {
    Field f = Field();
    f.work();
}