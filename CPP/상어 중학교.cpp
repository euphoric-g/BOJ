#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// #define DEBUG

#define MAX_SIZE 21

#define RAINBOW 0
#define STONE -1
#define BLANK -2

typedef std::pair<int, int> Pos;

const int xdiff[4] = {0, -1, 0, 1};
const int ydiff[4] = {1, 0, -1, 0};

class Cell {
    public:
    Pos p;
    int state;
    bool visited;
    Cell() {}
    Cell(Pos cur, int s) { state = s; visited = false; p = cur; }
};

bool compare_body(const Cell &a, const Cell &b) {
    if(a.state == RAINBOW) {
        return 1 > 2;
    } else if(b.state == RAINBOW) {
        return 1 < 2;
    } else if(a.p.first != b.p.first) {
        return a.p.first < b.p.first;
    } else {
        return a.p.second < b.p.second;
    }
}

class Chunk {
    public:
    std::vector<Cell> body;
    int rainbows;
    int type;
    Pos standard;
    Chunk() { rainbows = 0; }
    void push(Cell c) {
        body.push_back(c);
        if(c.state == RAINBOW) rainbows++;
    }
    void set_standard() {
        std::sort(body.begin(), body.end(), compare_body);
        standard = body.front().p;
    }
};

bool compare_chunk(const Chunk &a, const Chunk &b) {
    if(a.body.size() != b.body.size()) {
        return a.body.size() > b.body.size();
    } else if(a.rainbows != b.rainbows) {
        return a.rainbows > b.rainbows;
    } else if(a.standard.first != b.standard.first) {
        return a.standard.first > b.standard.first;
    } else {
        return a.standard.second > b.standard.second;
    }
}

class Mine {
    public:
    Cell grid[MAX_SIZE][MAX_SIZE];
    int size;
    int score;
    Mine() {}
    Mine(int sz) {
        size = sz;
        score = 0;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                int state_in;
                std::cin >> state_in;
                grid[i][j] = Cell(Pos(i, j), state_in);
            }
        }
    }
    void all_clear() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j].visited = false;
            }
        }
    }
    void rainbow_clear() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(grid[i][j].state == RAINBOW) grid[i][j].visited = false;
            }
        }
    }
    void set(Pos p) {
        grid[p.first][p.second].visited = true;
    }
    bool pos_check(Pos p) {
        return p.first >= 0 && p.first < size && p.second >= 0 && p.second < size;
    }
    bool type_check(Cell c) {
        return c.state != STONE && c.state != BLANK && c.state != RAINBOW;
    }
    bool type_check_2(Cell c, int type) {
        return c.state == type || c.state == RAINBOW;
    }
    void dig(Chunk c) {
        score += c.body.size() * c.body.size();
        for(const auto& b : c.body) {
            grid[b.p.first][b.p.second].state = BLANK;
        }
    }
    bool work() {
        #ifdef DEBUG
        std::cout << "work() entered\n";
        #endif
        all_clear();
        std::vector<Chunk> chunks;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                rainbow_clear();
                Pos cur = Pos(i, j);
                if(pos_check(cur) && type_check(grid[cur.first][cur.second]) && !grid[cur.first][cur.second].visited) {
                    // 좌표 괜찮고 해당 위치가 공백, 돌, 무지개 블록이 아니라면 탐색 시작
                    #ifdef DEBUG
                    std::cout << "start explore at [" << i << ", " << j << "]\n";
                    #endif
                    Chunk c = Chunk();
                    int start_type = grid[cur.first][cur.second].state;
                    std::queue<Pos> q;
                    q.push(cur);
                    c.push(grid[cur.first][cur.second]);
                    set(cur);
                    while(!q.empty()) {
                        Pos from = q.front(); q.pop();
                        for(int z=0; z<4; z++) {
                            Pos next = Pos(from.first + xdiff[z], from.second + ydiff[z]);
                            if(pos_check(next) && type_check_2(grid[next.first][next.second], start_type) && !grid[next.first][next.second].visited) {
                                #ifdef DEBUG
                                std::cout << "push [" << next.first << ", " << next.second << "]\n";
                                #endif
                                set(next);
                                q.push(next);
                                c.push(grid[next.first][next.second]);
                            }
                        }
                    }
                    if(c.body.size() > 1) {
                        c.set_standard();
                        chunks.push_back(c);
                        #ifdef DEBUG
                        std::cout << "Block from [" << i << ", " << j << "] is bigger than 1\n";
                        #endif
                    }
                }
            }
        }
        #ifdef DEBUG
        std::cout << "explore complete\n";
        #endif
        if(!chunks.empty()) {
            std::sort(chunks.begin(), chunks.end(), compare_chunk);
            Chunk chunk_to_dig = chunks.front();
            #ifdef DEBUG
            for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++) {
                    std::cout << grid[i][j].state << " ";
                }
                std::cout << std::endl;
            }
            for(const auto &c : chunk_to_dig.body) {
                std::cout << "[" << c.p.first << ", " << c.p.second << "] type = " << c.state << std::endl;
            }
            #endif
            dig(chunk_to_dig);
            fall();
            rotate();
            fall();
            #ifdef DEBUG
            for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++) {
                    std::cout << grid[i][j].state << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "score = " << score << std::endl;
            #endif
            return true;
        }
        return false;
    }
    void rotate() {
        Cell temp[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                temp[size-1-j][i] = grid[i][j];
            }
        }
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j] = temp[i][j];
                grid[i][j].p.first = i;
                grid[i][j].p.second = j;
            }
        }
    }
    void fall() {
        for(int i=size-1; i>=0; i--) {
            for(int j=0; j<size; j++) {
                Pos cur = Pos(i, j);
                if(grid[i][j].state != BLANK && grid[i][j].state != STONE) {
                    Pos next = Pos(i+1, j);
                    while(pos_check(next) && grid[next.first][next.second].state == BLANK) {
                        grid[next.first][next.second].state = grid[cur.first][cur.second].state;
                        grid[cur.first][cur.second].state = BLANK;
                        cur = next;
                        next = Pos(cur.first+1, cur.second);
                    }
                }
            }
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    Mine mine = Mine(n);
    while(mine.work()) {}
    std::cout << mine.score << std::endl;
}