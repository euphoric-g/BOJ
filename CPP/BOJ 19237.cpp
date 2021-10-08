#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_SIZE 20
#define MAX_SHARK ((MAX_SIZE) * (MAX_SIZE))
#define ALIVE 0
#define DEAD 1
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct std::vector<int> vint;
typedef struct std::queue<int> qint;

const int xdiff[4] = {-1, 1, 0, 0};
const int ydiff[4] = {0, 0, -1, 1};
class Pos {
    public:
    friend Pos operator+( Pos &a, Pos &b) {
        return Pos(a.x + b.x, a.y + b.y);
    }
    int x, y;
    Pos() {}
    Pos(int a, int b) { x = a; y = b; }
};
Pos diff[4] = {Pos(-1, 0), Pos(1, 0), Pos(0, -1), Pos(0, 1)};
// UP, DOWN, LEFT, RIGHT

class Scent {
    public:
    int owner;
    int time;
    Scent() {}
    Scent(int o, int t) {
        owner = o;
        time = t;
    }
};

class Cell {
    public:
    Scent smells[MAX_SHARK];
    Pos position;
    bool exist_shark;
    bool exist_smell;
    Cell() {}
    Cell(int x, int y) {
        position = Pos(x, y);
        for(int i=0; i<MAX_SHARK; i++) {
            smells[i] = Scent(i, 0);
        }
        exist_smell = false;
    }
    Cell(Pos p) { position = p; }
    bool exist_scent(int snum) {
        return smells[snum].time > 0;
    }
    bool no_scent() { return !exist_smell;}
    void make_smell(int snum, int life) {
        smells[snum].time = life;
    }
    void elapsed() {
        exist_smell = false;
        for(int i=0; i<MAX_SHARK; i++) {
            if(smells[i].time > 0) {
                smells[i].time--;
                if(smells[i].time > 0) exist_smell = true;
                // exist_smell = true;
            }
        }
    }
};

class Field {
    public:
    Cell grid[MAX_SIZE][MAX_SIZE];
    int size;
    Field() {}
    Field(int sz) {
        size = sz;
    }
    void elapsed() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j].elapsed();
            }
        }
    }
};

class Shark {
    public:
    bool state;
    int scent_life;
    void *ptr_field;
    Pos position;
    int view_dir;
    int num;
    int priority[4][4];
    Shark() {}
    Shark(int n) { num = n; state = ALIVE; }
    void set_priority(qint q) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                priority[i][j] = q.front();
                q.pop();
            }
        }
    }
    Pos get_pos() { return position; }
    void set_pos(int x, int y) { position = Pos(x, y); }
    void set_pos(Pos p) { position = p; }
    bool valid_position(Pos p) {
        int grid_size = ((Field *)ptr_field)->size;
        return p.x >= 0 && p.x < grid_size && p.y >= 0 && p.y < grid_size;
    }
    void move() {
        Field *ptr = (Field *)ptr_field;
        bool find = false;
        for(int i=0; i<4 && !find; i++) {
            Pos next = position + diff[priority[view_dir][i]];
            if(!valid_position(next)) continue;
            if(ptr->grid[next.x][next.y].no_scent()) {
                // std::cout << "Shark #" << num << " selects direction " << priority[view_dir][i] << std::endl;
                find = true;
                view_dir = priority[view_dir][i];
                position = next;
            }
        }
        for(int i=0; i<4 && !find; i++) {
            Pos next = position + diff[priority[view_dir][i]];
            if(!valid_position(next)) continue;
            if(ptr->grid[next.x][next.y].exist_scent(num)) {
                find = true;
                view_dir = priority[view_dir][i];
                position = next;
            }
        }
    }
    void smells() {
        Field *ptr = (Field *)ptr_field;
        ptr->grid[position.x][position.y].make_smell(num, scent_life);
    }
};

bool cmp(const Shark &a, const Shark &b) {
    return a.num < b.num;
}

bool end_condition(std::vector<Shark> sharks) {
    for(int i=0; i<sharks.size(); i++) {
        if(sharks[i].num != 1 && sharks[i].state == ALIVE) return false;
    }
    return true;
}

void print(Field f, std::vector<Shark> s) {
    int shark_cnt = 0;
    std::string dir_str[4] = {"UP", "DOWN", "LEFT", "RIGHT"};
    for(int i=0; i<s.size(); i++) {
        if(s[i].state == ALIVE) shark_cnt++;
        std::cout << "Shark #" << s[i].num << (s[i].state == ALIVE ? " ALIVE " : " DEAD ") << dir_str[s[i].view_dir] << " [" << s[i].position.x << ", " << s[i].position.y << "]" << std::endl;
    }
    std::cout << "Total " << shark_cnt << " alive sharks." << std::endl;
    for(int i=0; i<f.size; i++) {
        for(int j=0; j<f.size; j++) {
            std::string st = "(";
            for(int k=0; k<s.size(); k++) {
                if(f.grid[i][j].smells[s[k].num].time == 0) continue;
                std::string str = "[";
                str += std::to_string(f.grid[i][j].smells[s[k].num].owner);
                str += ", ";
                str += std::to_string(f.grid[i][j].smells[s[k].num].time);
                str += "]";
                st += str;
            }
            st += ") ";
            std::cout << st;
        }
        std::cout << std::endl;
    }
}

int main() {
    int N, M, k;
    int time_elapsed = 0;
    std::cin >> N >> M >> k;
    std::vector<Shark> sharks;
    Shark stemp[MAX_SHARK];
    Field f = Field(N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int val;
            std::cin >> val;
            f.grid[i][j] = Cell(i, j);
            if(val != 0) {
                stemp[val-1].num = val;
                stemp[val-1].set_pos(i, j);
                stemp[val-1].ptr_field = &f;
                stemp[val-1].scent_life = k+1;
            }
        }
    }
    for(int i=0; i<M; i++) {
        int dir_in;
        std::cin >> dir_in;
        stemp[i].view_dir = dir_in - 1;
    }
    for(int i=0; i<M; i++) {
        qint priority;
        for(int j=0; j<16; j++) {
            int prior_in;
            std::cin >> prior_in;
            priority.push(prior_in-1);
        }
        stemp[i].set_priority(priority);
    }
    for(int i=0; i<M; i++) {
        sharks.push_back(stemp[i]);
    }
    /*
    std::string dir_str[4] = {"UP", "DOWN", "LEFT", "RIGHT"};
    for(int i=0; i<sharks.size(); i++) {
        std::cout << "Shark #" << sharks[i].num << (sharks[i].state == ALIVE ? " ALIVE " : " DEAD ") << dir_str[sharks[i].view_dir] << " [" << sharks[i].position.x << ", " << sharks[i].position.y << "]" << std::endl;
    }
    */
    for(int i=0; i<sharks.size(); i++) sharks[i].smells();
    f.elapsed();
    while( !end_condition(sharks) && time_elapsed <= 1000) {
        // std::cout << "move start at time = " << time_elapsed << std::endl;
        for(int i=0; i<sharks.size(); i++) {
            if(sharks[i].state == ALIVE) {
                sharks[i].move();
            }
        }
        // 같은 칸에 들어간 상어 체크
        int check_shark[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<MAX_SIZE; i++) {
            for(int j=0; j<MAX_SIZE; j++) {
                check_shark[i][j] = 0;
            }
        }
        // std::cout << "Check shark" << std::endl;
        for(int i=0; i<sharks.size(); i++) {
            if(sharks[i].state == ALIVE) {
                if(check_shark[sharks[i].position.x][sharks[i].position.y] == 0) {
                    check_shark[sharks[i].position.x][sharks[i].position.y] = sharks[i].num;
                } else if(check_shark[sharks[i].position.x][sharks[i].position.y] < sharks[i].num) {
                    sharks[i].state = DEAD;
                }
            }
        }
        // std::cout << "shark smells" << std::endl;
        for(int i=0; i<sharks.size(); i++) {
            if(sharks[i].state == ALIVE) {
                sharks[i].smells();
            }
        }
        // print(f, sharks);
        time_elapsed++;
        f.elapsed();
    }
    std::cout << (time_elapsed <= 1000 ? time_elapsed : -1) << std::endl;
}