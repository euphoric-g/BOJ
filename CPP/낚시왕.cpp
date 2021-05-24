#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// #define DEBUG

#define NO_SHARK 0

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
#define ERROR 5

class Pos {
    public:
    int x, y;
    Pos() {}
    Pos(int a, int b) { x = a; y = b; }
};

Pos diff[5] = {
    Pos(0, 0), Pos(-1, 0), Pos(1, 0), Pos(0, 1), Pos(0, -1)
};

Pos add_pos(Pos a, Pos b) {
    return Pos(a.x+b.x, a.y+b.y);
}

bool valid(Pos next, int width, int height) {
    return next.x >= 0 && next.x < height && next.y >= 0 && next.y < width;
}

int rev_dir(int dir) {
    switch(dir) {
        case UP:
        return DOWN;
        case DOWN:
        return UP;
        case LEFT:
        return RIGHT;
        case RIGHT:
        return LEFT;
        default:
        return ERROR;
    }
}

class Shark {
    public:
    int field_width;
    int field_height;
    Pos loc;
    int speed;
    int size;
    int dir;
    bool moved;
    Shark() {}
    Shark(Pos p, int d, int s, int z, int fw, int fh) {
        loc = p; dir = d; speed = s; size = z; moved = false;
        field_width = fw; field_height = fh;
    }
    void move() {
        if(moved) {
            // do nothing
        } else {
            // 0 1 2 3 4 5 6 7 8
            // 161514131211109
            // 171819202122232425

            // x  x  0  1  2  3
            // 8  7  6  5  4
            //    9  10 11 12 13

            //    13 14 15 16 17
            // 12 11 10 9  8
            //    3  4  5  6  7
            // 2  1  0  x  x  x 
            moved = true;
            Pos next = add_pos(loc, Pos(speed * diff[dir].x, speed * diff[dir].y));
            if(valid(next, field_width, field_height)) {
                loc = next;
            } else {
                int target_len = (dir == UP || dir == DOWN) ? field_height : field_width;
                int new_speed = speed % (2 * (target_len - 1));
                while(new_speed-->0) {
                    next = add_pos(loc, diff[dir]);
                    if(valid(next, field_width, field_height)) {
                        loc = next;
                    } else {
                        dir = rev_dir(dir);
                        next = add_pos(loc, diff[dir]);
                        if(valid(next, field_width, field_height)) {
                            loc = next;
                        }
                    }
                }
            }
        }
    }
};

void push_shark(void *, Shark s);

class Cell {
    public:
    void *ptr_field;
    int field_width;
    int field_height;
    Pos loc;
    std::queue<Shark> sharks;
    Cell(){}
    Cell(void *ptr, Pos p, int fw, int fh) { ptr_field = ptr; loc = p; field_width = fw; field_height = fh; }
    int get_shark_num() { return (int)sharks.size(); }
    void add_shark(Pos p, int d, int s, int z) {
        sharks.push(Shark(p, d, s, z, field_width, field_height));
    }
    void flag_reset() {
        int sz = get_shark_num();
        for(int i=0; i<sz; i++) {
            Shark tmp = sharks.front();
            sharks.pop();
            tmp.moved = false;
            sharks.push(tmp);
        }
    }
    void add_shark(Shark s) { sharks.push(s); }
    void move_shark() {
        int sz = get_shark_num();
        for(int i=0; i<sz; i++) {
            Shark tmp = sharks.front();
            sharks.pop();
            tmp.move();
            push_shark(ptr_field, tmp);
        }
    }
    void kill_shark() {
        if(get_shark_num() > 1) {
            Shark biggest = Shark();
            biggest.size = -1;
            while(sharks.size() != 0) {
                Shark tmp = sharks.front();
                sharks.pop();
                if(tmp.size > biggest.size) biggest = tmp;
            }
            add_shark(biggest);
        }
    }
};

class Field {
    public:
    Cell grid[100][100];
    int width;
    int height;
    int score;
    int target;
    Field(){}
    Field(int r, int c) { 
        height = r; width = c; score = 0; target = -1;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                grid[i][j] = Cell(this, Pos(i, j), width, height);
            }
        }
    } 
    void flag_reset() {
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                grid[i][j].flag_reset();
            }
        }
    }
    void move_human() { target++; }
    void fishing() {
        bool end = false;
        for(int i=0; i<height && !end; i++) {
            if(grid[i][target].get_shark_num() != 0) {
                Shark get = grid[i][target].sharks.front();
                score += get.size;
#ifdef DEBUG
                printf("king of fishing caught shark with size %d at %d, %d. score is %d\n", get.size, i, target, score);
#endif
                grid[i][target].sharks.pop();
                end = true;
            }
        }
    }
    void move_shark() {
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                grid[i][j].move_shark();
            }
        }
    }
    void kill_shark() {
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                grid[i][j].kill_shark();
            }
        }
    }
    void simulation() {
        while(1) {
            flag_reset();
            move_human();
#ifdef DEBUG
            show();
#endif
            if(target == width) break;
            fishing();
            move_shark();
            kill_shark();
        }
    }
    void show() {
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                if(grid[i][j].get_shark_num() == 0) {
                    std::cout << "[blank " << i << ", " << j << "] ";
                } else {
                    Shark front = grid[i][j].sharks.front();
                    std::cout << "[z=" << front.size << ",d=" << front.dir << ",s=" << front.speed << "] ";
                }
            }
            std::cout << std::endl;
        }
    }
};

void push_shark(void *ptr, Shark s) {
    Field *pt = (Field *)ptr;
    pt->grid[s.loc.x][s.loc.y].add_shark(s);
}

int main() {
    int r, c, m;
    std::cin >> r >> c >> m;
    Field f = Field(r, c);
    for(int i=0; i<m; i++) {
        int shark_r, shark_c, shark_s, shark_d, shark_z;
        std::cin >> shark_r >> shark_c >> shark_s >> shark_d >> shark_z;
        Shark new_shark = Shark(Pos(shark_r-1, shark_c-1), shark_d, shark_s, shark_z, c, r);
        push_shark(&f, new_shark);
    }
    f.simulation();
    std::cout << f.score << std::endl;
}