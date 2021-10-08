#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iterator>

#define MAX_SIZE 12

#define WHITE 0
#define RED 1
#define BLUE 2
#define OUT_OF_BOARD 3

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

const int xdiff[5] = {0, 0, 0, -1, 1};
const int ydiff[5] = {0, 1, -1, 0, 0};

class Pos {
    public:
    int x, y, dir;
    Pos() {}
    Pos(int a, int b) { x = a; y = b; }
    Pos(int a, int b, int d) { x = a; y = b; dir = d; }
};

class Mal {
    public:
    void *ptr_mals;
    int num;
    int dir;
    Pos position;
    bool operator==(const Mal& m) { return (this->num == m.num); }
    bool operator==(const int n) { return (this->num == n); }
    Mal() {}
    Mal(int x, int y, int d, int n) {
        position = Pos(x, y);
        dir = d;
        num = n;
    }
    Pos destination() {
        return Pos(position.x+xdiff[dir], position.y+ydiff[dir], dir);
    }
    void set_position(Pos p) {
        position = p;
    }
};

class Mals {
    // container for Mal
    public:
    int size;
    int cnt_mals;
    std::vector<Mal> grid[MAX_SIZE][MAX_SIZE];
    int color[MAX_SIZE][MAX_SIZE];
    std::vector<Mal> mals;
    Mals() {}
    Mals(int sz) {
        cnt_mals = 0;
        size = sz;
    }
    void put(Mal m) {
        cnt_mals++;
        m.ptr_mals = (void *)this;
        mals.push_back(m);
        grid[m.position.x][m.position.y].push_back(m);
    }
    Pos turn_out(Pos p) {
        if(p.x >= 0 && p.x < size && p.y >= 0 && p.y < size && color[p.x][p.y] != BLUE) {
            // WHITE or RED
            return p;
        } else {
            // BLUE or OUT_OF_BOARD
            int redir;
            switch(p.dir) {
                case UP:
                redir = DOWN;
                break;
                case DOWN:
                redir = UP;
                break;
                case LEFT:
                redir = RIGHT;
                break;
                case RIGHT:
                redir = LEFT;
                break;
            }
            return Pos(p.x + 2 * xdiff[redir], p.y + 2 * ydiff[redir], redir);
        }
    }
    void show() {
        for(int i=0; i<cnt_mals; i++) {
            std::vector<Mal>::iterator it = std::find(mals.begin(), mals.end(), i+1);
            if(it != mals.end()) {
                std::cout << "mal #" << i << " at [" << it->position.x << ", " << it->position.y << "]" << std::endl;
            }
        }
    }
    void start_turn() {
        for(int i=1; i<=cnt_mals; i++) {
            std::vector<Mal>::iterator t = std::find(mals.begin(), mals.end(), i);
            Pos cur = t->position;
            Pos dest = t->destination();
            dest = turn_out(dest);
            int dest_c;
            if(dest.x >= 0 && dest.x < size && dest.y >= 0 && dest.y < size) {
                dest_c = color[dest.x][dest.y];
            } else {
                dest_c = OUT_OF_BOARD;
            }
            std::cout << "mal #" << i << " at [" << cur.x << ", " << cur.y << "] moves to [" << dest.x << ", " << dest.y << "]" << std::endl;
            if(dest_c == RED) {
                std::queue<Mal> temp;
                int tnum;
                while((tnum = grid[cur.x][cur.y].back().num) != i) {
                    std::vector<Mal>::iterator it = std::find(mals.begin(), mals.end(), tnum);
                    it->set_position(dest);
                    temp.push(*it);
                    grid[cur.x][cur.y].pop_back();
                }
                while(!temp.empty()) {
                    grid[dest.x][dest.y].push_back(temp.front());
                    temp.pop();
                }
            }
            if(dest_c == WHITE) {
                std::vector<Mal> temp;
                int tnum;
                while((tnum = grid[cur.x][cur.y].back().num) != i) {
                    std::vector<Mal>::iterator it = std::find(mals.begin(), mals.end(), tnum);
                    it->set_position(dest);
                    temp.push_back(*it);
                    grid[cur.x][cur.y].pop_back();
                }
                while(!temp.empty()) {
                    grid[dest.x][dest.y].push_back(temp.back());
                    temp.pop_back();
                }
            }
            if(dest_c == BLUE || dest_c == OUT_OF_BOARD) {
                // do nothing
            }
            if(end_condition() == true) break;
        }
    }
    bool end_condition() {
        int check[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<MAX_SIZE; i++) {
            for(int j=0; j<MAX_SIZE; j++) {
                check[i][j] = 0;
            }
        }
        for(int i=0; i<mals.size(); i++) {
            // std::cout << "mal num #" << i << " at [" << t->position.x << ", " << t->position.y << "]" << std::endl;
            if(++check[mals[i].position.x][mals[i].position.y] >= 4) {
                // std::cout << "end_condition true at [" << t->position.x << ", " << t->position.y << "]" << "with " << check[t->position.x][t->position.y] << std::endl;
                return true;
            }
        }
        return false;
    }
};

class Cell {
    public :
    int color;
    Pos p;
    Cell() {}
    Cell(int x, int y) {
        p = Pos(x, y);
    }
    void set_color(int c) { color = c; }
    int get_color() { return color; }
};

class Board {
    public:
    int size;
    Cell grid[MAX_SIZE][MAX_SIZE];
    Board(){}
    Board(int sz) { 
        size = sz;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j] = Cell(i, j);
            }
        }
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    Board b = Board(n);
    Mals mals = Mals(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int c;
            std::cin >> c;
            b.grid[i][j].set_color(c);
            mals.color[i][j] = c;
        }
    }
    for(int i=0; i<k; i++) {
        int x, y, dir;
        std::cin >> x >> y >> dir;
        Mal m = Mal(x-1, y-1, dir, i+1);
        mals.put(m);
    }
    int turn = 0;
    while(++turn <= 2 && !mals.end_condition()) {
        mals.start_turn();
        mals.show();
    }
    std::cout << turn << std::endl;
    return 0;
}