#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define LAND 0
#define WATER 1

const int rdiff[4] = {0, 0, 1, -1};
const int cdiff[4] = {1, -1, 0, 0};

class Cell {
    public:
    int r, c;
    int state;
    bool checked;
};

bool pos_check(int r, int c, int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

void clear(Cell **map, int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            map[i][j].checked = false;
        }
    }
}

int find_biggest_land(Cell **map, int r, int c) {
    int max_depth = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(map[i][j].state == LAND) {
                // 해당 위치부터 해당 육지의 깊이 탐색
                // 해당 깊이가 지금까지 깊이 중 가장 크다면 갱신
                clear(map, r, c);
                std::queue<Cell *> q;
                map[i][j].checked = true;
                q.push(&map[i][j]);
                int depth = -1;
                while(!q.empty()) {
                    depth++;
                    int sz = q.size();
                    while(sz-->0) {
                        Cell *cur = q.front(); q.pop();
                        for(int x=0; x<4; x++) {
                            if(pos_check(r, c, cur->r + rdiff[x], cur->c + cdiff[x])) {
                                Cell *next = &map[cur->r + rdiff[x]][cur->c + cdiff[x]];
                                if(next->state == LAND && !next->checked) {
                                    next->checked = true;
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
                max_depth = std::max(max_depth, depth);
            }
        }
    }
    return max_depth;
}

int main() {
    int r, c;
    std::cin >> r >> c;
    Cell **map = new Cell*[r];
    for(int i=0; i<r; i++) {
        map[i] = new Cell[c];
        for(int j=0; j<c; j++) {
            map[i][j].r = i;
            map[i][j].c = j;
            char in;
            std::cin >> in;
            map[i][j].state = (in == 'W') ? WATER : LAND;
        }
    }
    std::cout << find_biggest_land(map, r, c) << std::endl;
    delete[] map;
    return 0;
}