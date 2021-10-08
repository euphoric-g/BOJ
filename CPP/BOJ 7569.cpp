#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

#define RIPEN 1
#define RAW 0
#define BLANK -1

class Pos {
    public:
    int x, y, z;
    Pos() {}
    Pos(int a, int b, int c) {
        z = a;
        x = b;
        y = c;
    }
    Pos operator+(Pos a) {
        return Pos(z + a.z, x + a.x, y + a.y);
    }
    void show() {
        std::cout << "(" << z << ", " << x << ", " << y << ")\n";
    }
};

std::vector<Pos> diff = { Pos(0, 0, 1), Pos(0, 1, 0), Pos(1, 0, 0), Pos(0, 0, -1), Pos(0, -1, 0), Pos(-1, 0, 0) };

class Cell {
    public:
    bool visited;
    int state;
    int time;
    Cell() {}
};

class Box {
    public:
    Cell ***grid;
    int n, m, h;
    bool exist_tomato;
    bool all_ripen;
    Box() {
        std::cin >> m >> n >> h;
        all_ripen = true;
        exist_tomato = false;
        grid = (Cell ***)calloc(h, sizeof(Cell **));
        for(int i=0; i<h; i++) {
            grid[i] = (Cell **)calloc(n, sizeof(Cell *));
            for(int j=0; j<n; j++) {
                grid[i][j] = (Cell *)calloc(m, sizeof(Cell));
            }
        }
        for(int i=0; i<h; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<m; k++) {
                    int state;
                    std::cin >> state;
                    if(state == RAW) all_ripen = false;
                    if(state != BLANK) exist_tomato = true;
                    grid[i][j][k].state = state;
                    grid[i][j][k].time = 0;
                    grid[i][j][k].visited = false;
                }
            }
        }
    }
    void clear_all() {
        for(int i=0; i<h; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<m; k++) {
                    grid[i][j][k].visited = false;
                }
            }
        }
    }
    bool pos_check(Pos p) {
        return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m && p.z >= 0 && p.z < h;
    }
    bool is_visited(Pos p) {
        return grid[p.z][p.x][p.y].visited;
    }
    bool ripe_check(Pos p) {
        return state(p) == RIPEN;
    }
    bool is_tomato(Pos p) {
        return state(p) != BLANK;
    }
    int state(Pos p) {
        return grid[p.z][p.x][p.y].state;
    }
    void ripen(Pos p) {
        grid[p.z][p.x][p.y].state = RIPEN;
    }
    void visit(Pos p) {
        grid[p.z][p.x][p.y].visited = true;
    }
    int BFS() {
        clear_all();
        std::queue<Pos> q;
        int t = -1;
        for(int i=0; i<h; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<m; k++) {
                    Pos cur = Pos(i, j, k);
                    if(state(cur) == RIPEN) {
                        grid[cur.z][cur.x][cur.y].time = 1;
                        visit(cur);
                        q.push(cur);
                    }
                }
            }
        }
        while(!q.empty()) {
            int sz = q.size();
            t++;
            while(sz-->0) {
                Pos get = q.front(); q.pop();
                for(auto &dif : diff) {
                    Pos next = get + dif;
                    if(pos_check(next) && !is_visited(next) && state(next) == RAW) {
                        grid[next.z][next.x][next.y].time = grid[get.z][get.x][get.y].time + 1;
                        visit(next);
                        q.push(next);
                    }
                }
            }
        }
        int max_time = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<m; k++) {
                    if(state(Pos(i, j, k)) == RAW) {
                        max_time = std::max(grid[i][j][k].time, max_time);
                    }
                    if(grid[i][j][k].state == RAW && grid[i][j][k].time == 0) {
                        return -1;
                    }
                }
            }
        }
        return max_time - 1;
    }
    void close() {
        free(grid);
    }
};

Box box = Box();

int main() {
    if(!box.exist_tomato) {
        std::cout << "-1\n";
        box.close();
        return 0;
    }
    if(box.all_ripen) {
        std::cout << "0\n";
        box.close();
        return 0;
    }
    std::cout << box.BFS() << '\n';
    box.close();
    return 0;
}