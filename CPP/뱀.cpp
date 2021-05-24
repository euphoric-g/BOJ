#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define GOOD 0
#define BAD -1

int rotate_right(int dir) { return (dir+1)%4; }
int rotate_left(int dir) { return (dir+3)%4; }

const int rdiff[4] = {-1, 0, 1, 0};
const int cdiff[4] = {0, 1, 0, -1};

class Body {
    public:
    int r, c;
    Body() {}
    Body(int i, int j) {
        r = i; c = j;
    }
};

class Snake {
    public:
    bool apple[100][100];
    int time;
    int dir;
    std::deque<Body> body;
    std::queue<std::pair<int, char>> operations;
    int size;
    Snake() { }
    Snake(int sz) {
        time = 0;
        dir = RIGHT;
        body.push_back(Body(0, 0));
        size = sz;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                apple[i][j] = false;
            }
        }
    }
    bool location_check(Body b) {
        return b.r >= 0 && b.r < size && b.c >= 0 && b.c < size;
    }
    bool body_check(Body b) {
        for(const auto &comp : body) {
            if(comp.r == b.r && comp.c == b.c) {
                return false;
            }
        }
        return true;
    }
    bool exist_apple(Body b) {
        return apple[b.r][b.c];
    }
    void eat(Body b) {
        apple[b.r][b.c] = false;
    }
    void turn(char op) {
        if(op == 'L') dir = rotate_left(dir);
        if(op == 'D') dir = rotate_right(dir);
    }
    int move() {
        time++;
        Body head = body.front();
        int new_r = head.r + rdiff[dir];
        int new_c = head.c + cdiff[dir];
        Body new_head = Body(new_r, new_c);
        if(location_check(new_head) && body_check(new_head)) {
            body.push_front(new_head);
        } else {
            return BAD;
        }
        if(!exist_apple(new_head)) {
            body.pop_back();
        } else eat(new_head);
        if(!operations.empty() && operations.front().first == time) {
            turn(operations.front().second);
            operations.pop();
        }
        return GOOD;
    }
    int run() {
        while(move() != BAD) { }
        return time;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    Snake dummy = Snake(n);
    for(int i=0; i<k; i++) {
        int r, c;
        std::cin >> r >> c;
        dummy.apple[r-1][c-1] = true;
    }
    int l;
    std::cin >> l;
    for(int i=0; i<l; i++) {
        int x;
        char c;
        std::cin >> x >> c;
        dummy.operations.push(std::pair<int, char>(x, c));
    }
    std::cout << dummy.run() << std::endl;
}