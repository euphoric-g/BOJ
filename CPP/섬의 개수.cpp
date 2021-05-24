#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define LAND 1
#define SEA 0

class Pos {
    public:
    int x, y;
    int state;
    bool visited;
    Pos() {}
    Pos(int a, int b) { x=a; y=b; visited = false; }
};

const int xdif[8] = {0, 0, -1, 1, 1, 1, -1, -1};
const int ydif[8] = {-1, 1, 0, 0, 1, -1, 1, -1};

bool check(int r, int c, int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int main() {
    while(1) {
        int w, h;
        std::cin >> w >> h;
        if(w == 0 && h == 0) break;
        Pos map[51][51];
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                int in;
                map[i][j] = Pos(i, j);
                std::cin >> in;
                map[i][j].state = in;
            }
        }
        int lands = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(map[i][j].state == LAND && !map[i][j].visited) {
                    lands++;
                    // std::cout << "Land #" << lands << " [" << i << ", " << j << "]\n";
                    map[i][j].visited = true;
                    std::queue<Pos> q;
                    q.push(map[i][j]);
                    while(!q.empty()) {
                        Pos get = q.front(); q.pop();
                        map[get.x][get.y].visited = true;
                        for(int k=0; k<8; k++) {
                            Pos next = Pos(get.x+xdif[k], get.y+ydif[k]);
                            if(check(h, w, next.x, next.y) && !map[next.x][next.y].visited && map[next.x][next.y].state == LAND) {
                                map[next.x][next.y].visited = true;
                                // std::cout << "with dir " << k << " [" << next.x << ", " << next.y << "]\n";
                                q.push(map[next.x][next.y]);
                            }
                        }
                    }
                }
            }
        }
        std::cout << lands << std::endl;
    }
    return 0;
}