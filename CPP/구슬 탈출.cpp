#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define NORMAL 0
#define SUCCESS 1
#define FAIL 2

#define WALL -1
#define BLANK -2
#define HOLE -3
#define RED -4
#define BLUE -5

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

const int xdiff[4] = {-1, 0, 1, 0};
const int ydiff[4] = {0, 1, 0, -1};

class Pos {
    public:
    int x, y;
    Pos() {}
    Pos(int a, int b) { x=a; y=b; }
    Pos add(Pos b) { return Pos(x+b.x, y+b.y); }
};

class Cell {
    public:
    int state;
    bool visited;
    Cell() {}
    Cell(char c) {
        switch(c) {
            case '#':
            state = WALL;
            break;
            case '.':
            state = BLANK;
            break;
            case 'O':
            state = HOLE;
            break;
            case 'R':
            state = RED;
            break;
            case 'B':
            state = BLUE;
            break;
        }
        visited = false;
    }
    void clear() { visited = false; }
    void set() { visited = true; }
};

class Board {
    public:
    int h, w;
    Cell grid[12][12];
    Pos red;
    Pos blue;
    int status;
    Board() {
        status = NORMAL;
        std::cin >> h >> w;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                char c;
                std::cin >> c;
                grid[i][j] = Cell(c);
                if(grid[i][j].state == BLUE) blue = Pos(i, j);
                if(grid[i][j].state == RED) red = Pos(i, j);
            }
        }
    }
    void show() {
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                switch(grid[i][j].state) {
                    case WALL:
                    std::cout << "#";
                    break;
                    case BLANK:
                    std::cout << ".";
                    break;
                    case RED:
                    std::cout << "R";
                    break;
                    case BLUE:
                    std::cout << "B";
                    break;
                    case HOLE:
                    std::cout << "O";
                    break;
                }
            }
            std::cout << std::endl;
        }
        std::cout << (status == NORMAL ? "NORMAL" : "SUCCESS") << std::endl;
    }
    Board tilt(int dir) {
        bool flag = false;
        Board ret = *this;
        Pos dif = Pos(xdiff[dir], ydiff[dir]);
        while(1) {
            // std::cout << "red moves " << dir << ", current position is [" << ret.red.x << ", " << ret.red.y << "]\n";
            // 빨간 구슬 이동
            Pos red_next = ret.red.add(dif);
            // std::cout << "next position is [" << red_next.x << ", " << red_next.y << "]\n";
            if(red_next.x >= 0 && red_next.x < h && red_next.y >= 0 && red_next.y < w) {
                if(ret.grid[red_next.x][red_next.y].state == BLANK) {
                    // 빈 공간을 만난다면 이동
                    ret.grid[ret.red.x][ret.red.y].state = BLANK;
                    ret.grid[red_next.x][red_next.y].state = RED;
                    ret.red = red_next;
                } else if(ret.grid[red_next.x][red_next.y].state == HOLE) {
                    // 구멍을 만나면 일단 멈추고 파란 구슬을 굴림
                    // 파란 구슬이 구멍에 빠지지 않으면 성공, 구멍에 빠지면 실패
                    ret.grid[ret.red.x][ret.red.y].state = BLANK;
                    while(1) {
                        // 파란 구슬 이동
                        Pos blue_next = ret.blue.add(dif);
                        if(blue_next.x >= 0 && blue_next.x < h && blue_next.y >= 0 && blue_next.y < w) {
                            if(ret.grid[blue_next.x][blue_next.y].state == BLANK) {
                                ret.grid[ret.blue.x][ret.blue.y].state = BLANK;
                                ret.grid[blue_next.x][blue_next.y].state = BLUE;
                                ret.blue = blue_next;
                            } else if(ret.grid[blue_next.x][blue_next.y].state == HOLE) {
                                // 파란 구슬이 구멍에 빠졌으므로 실패
                                ret.grid[ret.blue.x][ret.blue.y].state = BLANK;
                                ret.grid[ret.red.x][ret.red.y].state = BLANK;
                                ret.status = FAIL;
                                return ret;
                            } else if(ret.grid[blue_next.x][blue_next.y].state == RED) {
                                // 멈춤
                                break;
                            } else if(ret.grid[blue_next.x][blue_next.y].state == WALL) {
                                // 멈춤
                                break;
                            }
                        }
                    }
                    ret.status = SUCCESS;
                    return ret;
                } else if(ret.grid[red_next.x][red_next.y].state == BLUE) {
                    // 파란 구슬을 만나면 일단 멈추고 파란 구슬 이동.
                    // 파란 구슬 이동은 최초 1회만 실행
                    // 파란 구슬의 이동이 끝나면 마저 이동
                    // 만약 파란 구슬이 구멍을 만났다면 실패
                    if(!flag) {
                        while(1) {
                            // 파란 구슬 이동
                            Pos blue_next = ret.blue.add(dif);
                            if(blue_next.x >= 0 && blue_next.x < h && blue_next.y >= 0 && blue_next.y < w) {
                                if(ret.grid[blue_next.x][blue_next.y].state == BLANK) {
                                    ret.grid[ret.blue.x][ret.blue.y].state = BLANK;
                                    ret.grid[blue_next.x][blue_next.y].state = BLUE;
                                    ret.blue = blue_next;
                                } else if(ret.grid[blue_next.x][blue_next.y].state == HOLE) {
                                    ret.grid[ret.blue.x][ret.blue.y].state = BLANK;
                                    ret.status = FAIL;
                                    return ret;
                                    // 종료
                                } else if(ret.grid[blue_next.x][blue_next.y].state == RED) {
                                    // 멈춤
                                    break;
                                } else if(ret.grid[blue_next.x][blue_next.y].state == WALL) {
                                    // 멈춤
                                    break;
                                }
                            }
                        }
                        flag = true;
                    } else {
                        // 파란 구슬을 이동시킨 후에도 파란 구슬과 만났다면 해당 위치에서 멈춤
                        break;
                    }
                } else if(ret.grid[red_next.x][red_next.y].state == WALL) {
                    // 벽을 만났다면 해당 위치에서 멈춤
                    break;
                }
            }
        }
        while(1) {
            // 파란 구슬 이동
            // std::cout << "blue moves " << dir << ", current position is [" << ret.blue.x << ", " << ret.blue.y << "]\n";
            Pos blue_next = ret.blue.add(dif);
            // std::cout << "next position is [" << blue_next.x << ", " << blue_next.y << "]\n";
            if(blue_next.x >= 0 && blue_next.x < h && blue_next.y >= 0 && blue_next.y < w) {
                if(ret.grid[blue_next.x][blue_next.y].state == BLANK) {
                    ret.grid[ret.blue.x][ret.blue.y].state = BLANK;
                    ret.grid[blue_next.x][blue_next.y].state = BLUE;
                    ret.blue = blue_next;
                } else if(ret.grid[blue_next.x][blue_next.y].state == HOLE) {
                    // 파란 구슬이 구멍에 빠졌으므로 실패
                    ret.grid[ret.blue.x][ret.blue.y].state = BLANK;
                    ret.grid[ret.red.x][ret.red.y].state = BLANK;
                    ret.status = FAIL;
                    return ret;
                } else if(ret.grid[blue_next.x][blue_next.y].state == RED) {
                    // 멈춤
                    break;
                } else if(ret.grid[blue_next.x][blue_next.y].state == WALL) {
                    // 멈춤
                    break;
                }
            }
        }
        return ret;
    }
};

int func(Board b, int moves) {
    if(b.status == FAIL || moves == 0) {
        return FAIL;
    } else if(b.status == SUCCESS) {
        return moves;
    } else {
        bool flag = false;
        for(int i=0; i<4; i++) {
            Board c = b.tilt(i);
            if(c.status == SUCCESS) {
                return moves;
            } else if(c.status == FAIL) {
            } else {
                if(func(c, moves-1) != (FAIL || NORMAL)) flag = true;
            }
        }
        if(flag) return moves;
        else return FAIL;
    }
}
int main() {
    Board b = Board();
    int rtn_val = func(b, 10);
    std::cout << (rtn_val == FAIL ? -1 : 11-rtn_val) << std::endl;
}