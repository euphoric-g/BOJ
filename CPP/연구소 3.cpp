#include <iostream>
#include <algorithm>
#include <queue>

#define DEBUG

#define EMPTY 0
#define WALL 1
#define VIRUS 2
#define ACTIVE 3
#define INACTIVE 4

#define CHAR_INACTIVE 'I'
#define CHAR_ACTIVE 'A'
#define CHAR_VIRUS 'V'
#define CHAR_WALL 'W'
#define CHAR_EMPTY '-'

class Cell {
    public:
    int time;
    int x, y;
    int state;
    bool checked;
    Cell(){}
    Cell(int a, int b) { x = a; y = b; checked = false; time = 0; }
    void clear() { checked = false; }
    void set() { checked = true; }
};

class Lab {
    public:
    const char char_show[5] = {CHAR_EMPTY, CHAR_WALL, CHAR_VIRUS, CHAR_ACTIVE, CHAR_INACTIVE};
    int size;
    Cell grid[50][50];
    Lab(){}
    Lab(int n) { 
        size = n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = Cell(i,j);
            }
        }
    }
    Cell *nearby(int x, int y, int dir) {
        const int xdiff[4] = {0, 0, -1, 1};
        const int ydiff[4] = {1, -1, 0, 0};
        int new_x = x + xdiff[dir];
        int new_y = y + ydiff[dir];
        if(new_x >= 0 && new_x < size && new_y >= 0 && new_y < size) {
            return &grid[new_x][new_y];
        } else {
            return NULL;
        }
    }
    void check_clear() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j].clear();
            }
        }
    }
    void show() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                std::cout << char_show[grid[i][j].state];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    int biggest_block() {
        Lab lab = *this;
        int ret = -1;
        std::queue<Cell *>q;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(lab.grid[i][j].state != WALL && !lab.grid[i][j].checked) {
                    lab.grid[i][j].set();
                    q.push(&lab.grid[i][j]);
                    int tmp_big = 0;
                    while(!q.empty()) {
                        int qsz = q.size();
                        for(int k=0; k<qsz; k++) {
                            Cell *tmp_cell = q.front();
                            q.pop();
                            if(!tmp_cell->checked) {
                                tmp_cell->set();
                                for(int x=0; x<4; x++) {
                                    Cell *cell;
                                    if((cell = nearby(tmp_cell->x, tmp_cell->y, x)) != NULL && !cell->checked) {
                                        cell->set();
                                        q.push(cell);
                                    }
                                }
                            }
                        }
                        tmp_big++;
                    }
                    ret = tmp_big > ret ? tmp_big : ret;
                }
            }
        }
        return ret;
    }
    int simulate() {
        check_clear();
        std::queue<Cell *>q;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(grid[i][j].state == ACTIVE) {
                    q.push(&grid[i][j]);
                    grid[i][j].set();
                }
            }
        }
        int time = -1;
        while(!q.empty()) {
            int sz = q.size();
            time++;
            for(int i=0; i<sz; i++) {
                Cell *tmp = q.front(); q.pop();
                if(tmp->state != INACTIVE) tmp->state = ACTIVE;
                tmp->set();
                if(tmp->time != 0) tmp->time = std::min(tmp->time, time);
                else tmp->time = time;
                for(int x=0; x<4; x++) {
                    Cell *next = nearby(tmp->x, tmp->y, x);
                    if(next != NULL && !next->checked && next->state != WALL) {
                        if(next->state != INACTIVE) next->state = ACTIVE;
                        next->set();
                        q.push(next);
                    }
                }
            }
        }
        /*
        show();
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(grid[i][j].state == WALL) {
                    std::cout << "W ";
                } else {
                    std::cout << grid[i][j].time << " ";
                }
            }
            std::cout << std::endl;
        }
        */
        int max_time = -1;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(grid[i][j].state == WALL || grid[i][j].state == INACTIVE) {
                    continue;
                }
                if(grid[i][j].time == 0 && !grid[i][j].checked) {
                    // 미방문된 칸이 있는 경우
                    return INT32_MAX;
                }
                if(max_time == -1) { max_time = grid[i][j].time; }
                max_time = std::max(max_time, grid[i][j].time);
            }
        }
        return max_time;
    }
};

int backtracking(int *arr, Lab lab, int total, int m, int selected, int from) {
    int *test = new int[total]{0, };
    for(int i=0; i<selected; i++) {
        if(++test[arr[i]] > 1) {
            delete[] test;
            return INT32_MAX;
        }
    }
    if(m == selected) {
        int cnt = 0;
        Lab copied = lab;
        for(int i=0; i<copied.size; i++) {
            for(int j=0; j<copied.size; j++) {
                if(copied.grid[i][j].state == VIRUS) {
                    if(test[cnt++] == 1) {
                        copied.grid[i][j].state = ACTIVE;
                    } else {
                        copied.grid[i][j].state = INACTIVE;
                    }
                }
            }
        }
        delete[] test;
        return copied.simulate();
    }
    int ret = INT32_MAX;
    for(int i=from+1; i<total; i++) {
        arr[selected] = i;
        int test_result = backtracking(arr, lab, total, m, selected+1, i);
        ret = std::min(ret, test_result);
    }
    return ret;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int left = 0;
    Lab lab = Lab(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int s;
            std::cin >> s;
            if(s == VIRUS) left++;
            lab.grid[i][j].state = s;
        }
    }
    int *arr = new int[n]{0, };
    int result = backtracking(arr, lab, left, m, 0, -1);
    std::cout << (result == INT32_MAX ? -1 : result) << std::endl;
    // lab.show();
}