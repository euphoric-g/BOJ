#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_SIZE 64

class Pos {
    public:
    int x, y;
    Pos(){}
    Pos(int a, int b) {
        x = a; y = b;
    }
};

class Cell {
    public:
    int ice;
    Pos p;
    Cell() { ice = 0; }
    Cell(int a) { ice = a; }
    Cell(int a, int x, int y) { ice = a; p = Pos(x, y); }
};

class Field {
    public:
    const int xdiff[4] = {0, 0, -1, 1};
    const int ydiff[4] = {1, -1, 0, 0};
    int size;
    Cell ice[MAX_SIZE][MAX_SIZE];
    Field(int sz) {
        size = sz;
    }
    void show() {
        for(int i=0; i<(1<<size); i++) {
            for(int j=0; j<(1<<size); j++) {
                std::cout << ice[i][j].ice << " ";
            }
            std::cout << std::endl;
        }
    }
    void rotate(int x, int y, int lat_sz) {
        std::vector<Cell> vec;
        for(int i=x; i<x+lat_sz; i++) {
            for(int j=y; j<y+lat_sz; j++) {
                vec.push_back(ice[i][j]);
            }
        }
        for(int i=y; i<y+lat_sz; i++) {
            for(int j=x+lat_sz-1; j>=x; j--) {
                Cell temp = vec.back();
                vec.pop_back();
                ice[j][i] = temp;
            }
        }
    }
    bool valid(int x, int y) {
        return (x >= 0) && (x < (1<<size)) && (y >= 0) && (y < (1<<size));
    }
    bool check(int x, int y) {
        int cnt = 0;
        for(int i=0; i<4; i++) {
            int nx = x + xdiff[i];
            int ny = y + ydiff[i];
            if(valid(nx, ny) && ice[nx][ny].ice > 0) {
                cnt++;
            }
        }
        return (cnt >= 3) ? true : false;
    }
    void firestorm(int level) {
        int lattice_size = (1 << level);
        // 부분 격자의 가로 세로 크기
        int width = (1 << (size - level));
        // 필드 크기 / 가로, 세로 크기 = 한 변에 들어가는 부분 격자 수
        int num = width * width;
        // 부분 격자의 총 개수
        for(int i=0; i<(1<<size); i += lattice_size) {
            for(int j=0; j<(1<<size); j += lattice_size) {
                // (i, j) = 부분 격자의 왼쪽 위 모서리 좌표
                // lattice_size = 부분 격자의 가로 세로 크기
                rotate(i, j, lattice_size);
            }
        }
        int check_array[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<(1<<size); i++) {
            for(int j=0; j<(1<<size); j++) {
                if(ice[i][j].ice <= 0) {
                    check_array[i][j] = 0;
                    continue;
                }
                if(check(i, j) == false) check_array[i][j] = 1;
                else check_array[i][j] = 0;
            }
        }
        for(int i=0; i<(1<<size); i++) {
            for(int j=0; j<(1<<size); j++) {
                ice[i][j].ice -= check_array[i][j];
            }
        }
    }
    int sum() {
        int s = 0;
        for(int i=0; i<(1<<size); i++) {
            for(int j=0; j<(1<<size); j++) {
                s += ice[i][j].ice;
            }
        }
        return s;
    }
    int largest_ice_size() {
        int max_size = 0;
        bool checked[MAX_SIZE][MAX_SIZE];
        for(int i=0; i<(1<<size); i++) {
            for(int j=0; j<(1<<size); j++) {
                ice[i][j].p = Pos(i, j);
            }
        }
        for(int i=0; i<MAX_SIZE; i++) {
            for(int j=0; j<MAX_SIZE; j++) {
                checked[i][j] = false;
            }
        }
        for(int i=0; i<(1<<size); i++) {
            for(int j=0; j<(1<<size); j++) {
                if(!checked[i][j] && ice[i][j].ice > 0) {
                    checked[i][j] = true;
                    std::queue<Cell> q;
                    q.push(ice[i][j]);
                    int depth = 1;
                    while(!q.empty()) {
                        int sz = q.size();
                        for(int k=0; k<sz; k++) {
                            Cell temp = q.front();
                            q.pop();
                            if(temp.ice > 0) {
                                for(int z=0; z<4; z++) {
                                    int nx = temp.p.x+xdiff[z];
                                    int ny = temp.p.y+ydiff[z];
                                    if(valid(nx, ny)) {
                                        Cell next = ice[nx][ny];
                                        if(next.ice > 0 && !checked[nx][ny]) {
                                            q.push(next);
                                            depth++;
                                            checked[nx][ny] = true;
                                        }
                                    } else {
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    max_size = depth > max_size ? depth : max_size;
                }
            }
        }
        return max_size;
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;
    Field f = Field(n);
    for(int i=0; i<(1<<n); i++) {
        for(int j=0; j<(1<<n); j++) {
            int ice;
            std::cin >> ice;
            f.ice[i][j] = Cell(ice, i, j);
        }
    }
    while(q-->0) {
        int lv;
        std::cin >> lv;
        f.firestorm(lv);
    }
    std::cout << f.sum() << std::endl;
    std::cout << f.largest_ice_size() << std::endl;
    return 0;
}