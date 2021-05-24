#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define BLANK 0
#define SHARK -2

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

const int xdiff[5] = {0, -1, 1, 0, 0};
const int ydiff[5] = {0, 0, 0, -1, 1};

class Pos {
    public:
    int x, y;
    Pos() {}
    Pos(int a, int b) { x=a; y=b; }
};

class Cell {
    public:
    Pos p;
    int dir;
    int num;
    Pos next;
    Cell() {}
    Cell(Pos cur) { p = cur; }
    Cell(Pos cur, int d) {
        p = cur;
        dir = (d % 2 == 0) ? d-1 : d+1;
        next = Pos(cur.x + xdiff[d], cur.y + ydiff[d]);
    }

};

class Spell {
    public:
    int dir;
    int distance;
    Spell() {}
    Spell(int di, int si) { dir = di; distance = si; }
};

class Field {
    public:
    int n, m;
    int score;
    Cell grid[51][51];
    std::queue<Spell> spells;
    std::vector<Pos> route;
    bool pos_check(Pos p) {
        return p.x >= 0 && p.x < n && p.y >= 0 && p.y < n;
    }
    Field() {
        std::cin >> n >> m;
        score = 0;
        int arr[51][51];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                std::cin >> arr[i][j];
            }
        }
        for(int i=0; i<m; i++) {
            int di, si;
            std::cin >> di >> si;
            spells.push(Spell(di, si));
        }
        int cur_dir = LEFT;
        Pos cur = Pos(n/2, n/2);
        for(int i=0; i<2*n-1; i++) {
            for(int j=0; j<i/2+1; j++) {
                cur = Pos(cur.x + xdiff[cur_dir], cur.y + ydiff[cur_dir]);
                if(cur.x >= 0 && cur.x < n && cur.y >= 0 && cur.y < n) {
                    route.push_back(cur);
                    grid[cur.x][cur.y] = Cell(cur, cur_dir);
                    grid[cur.x][cur.y].num = arr[cur.x][cur.y];
                }
            }
            // UP 1 DOWN 2 LEFT 3 RIGHT 4
            switch(cur_dir) {
                case UP:
                cur_dir = LEFT;
                break;
                case DOWN:
                cur_dir = RIGHT;
                break;
                case LEFT:
                cur_dir = DOWN;
                break;
                case RIGHT:
                cur_dir = UP;
                break;
            }
        }
        grid[n/2][n/2].num = SHARK;
    }
    void destroy() {
        Spell get = spells.front(); spells.pop();
        for(int i=1; i<=get.distance; i++) {
            Pos target = Pos(n/2 + i*xdiff[get.dir], n/2 + i*ydiff[get.dir]);
            if(pos_check(target)) grid[target.x][target.y].num = BLANK;
        }
        // std::cout << "Magician shark spells. [" << get.dir << ", " << get.distance << "]\n";
        // show();
    }
    void draw() {
        for(const auto& p : route) {
            if(grid[p.x][p.y].num != BLANK) {
                Pos cur = p;
                while(1) {
                    Pos next = Pos(cur.x + xdiff[grid[cur.x][cur.y].dir], cur.y+ydiff[grid[cur.x][cur.y].dir]);
                    if(pos_check(next) && grid[next.x][next.y].num == BLANK) {
                        grid[next.x][next.y].num = grid[cur.x][cur.y].num;
                        grid[cur.x][cur.y].num = BLANK;
                        cur = next;
                    } else {
                        break;
                    }
                }
            }
        }
        // std::cout << "after draw..\n";
        // show();
    }
    bool explode() {
        typedef std::pair<Pos, int> data_type;
        std::vector<data_type> vec;
        for(const auto& p : route) {
            if(vec.empty()) {
                vec.push_back(data_type(p, grid[p.x][p.y].num));
            } else {
                if(vec.back().second == grid[p.x][p.y].num) {
                    vec.push_back(data_type(p, grid[p.x][p.y].num));
                } else {
                    if(vec.size() > 3) {
                        for(const auto& loc : vec) {
                            // std::cout << "Explode " << grid[loc.first.x][loc.first.y].num << " at [" << loc.first.x << ", " << loc.first.y << "]\n";
                            score += grid[loc.first.x][loc.first.y].num;
                            grid[loc.first.x][loc.first.y].num = BLANK;
                        }
                        return true;
                    }
                    vec.clear();
                    vec.push_back(data_type(p, grid[p.x][p.y].num));
                }
            }
        }
        return false;
    }
    void change() {
        typedef std::pair<Pos, int> data_type;
        std::queue<int> new_numbers;
        std::vector<data_type> vec;
        for(const auto& p : route) {
            if(grid[p.x][p.y].num == BLANK) break;
            if(vec.empty()) {
                vec.push_back(data_type(p, grid[p.x][p.y].num));
            } else {
                if(vec.back().second == grid[p.x][p.y].num) {
                    vec.push_back(data_type(p, grid[p.x][p.y].num));
                } else {
                    new_numbers.push(vec.size());
                    new_numbers.push(vec.back().second);
                    vec.clear();
                    vec.push_back(data_type(p, grid[p.x][p.y].num));
                }
            }
        }
        if(!vec.empty()) {
            new_numbers.push(vec.size());
            new_numbers.push(vec.back().second);
        }
        for(const auto& p : route) {
            grid[p.x][p.y].num = new_numbers.empty() ? BLANK : new_numbers.front();
            if(!new_numbers.empty()) new_numbers.pop();
        }
        // std::cout << "after change...\n";
        // show();
    }
    void turn() {
        destroy();
        draw();
        while(explode()) { draw(); }
        change();
    }
    void run() {
        while(!spells.empty()) { turn(); }
        std::cout << score << std::endl;
    }
    void show() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                std::cout << grid[i][j].num << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    Field f = Field();
    f.run();
}