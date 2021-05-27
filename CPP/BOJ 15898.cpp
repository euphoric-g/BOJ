#include <iostream>
#include <algorithm>
#include <vector>

#define RED 0
#define BLUE 1
#define GREEN 2
#define YELLOW 3
#define WHITE 4

class Pos {
    public:
    int x, y;
    Pos() {}
    Pos(int a, int b) { x=a; y=b; }
};

const Pos standards[4] = { Pos(0, 0), Pos(0, 1), Pos(1, 0), Pos(1, 1) };

class Cell {
    public:
    int quality;
    int element;
    Cell() {}
    Cell(int q, int e) {
        quality = q; element = e;
    }
};

class Ingredient {
    public:
    Cell body[4][4];
    Ingredient() {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                std::cin >> body[i][j].quality;
            }
        }
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                char in;
                std::cin >> in;
                switch(in) {
                    case 'R' :
                    body[i][j].element = RED;
                    break;
                    case 'B' :
                    body[i][j].element = BLUE;
                    break;
                    case 'G' :
                    body[i][j].element = GREEN;
                    break;
                    case 'Y' :
                    body[i][j].element = YELLOW;
                    break;
                    case 'W' :
                    body[i][j].element = WHITE;
                    break;
                }
            }
        }
    }
    Ingredient CW() {
        Ingredient copy = *this;
        Cell temp[4][4];
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                temp[j][3-i] = copy.body[i][j];
            }
        }
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                copy.body[i][j] = temp[i][j];
            }
        }
        return copy;
    }
    std::vector<Ingredient> rotates() {
        std::vector<Ingredient> ret;
        Ingredient R0 = *this;
        Ingredient R90 = R0.CW();
        Ingredient R180 = R90.CW();
        Ingredient R270 = R180.CW();
        ret.push_back(R0);
        ret.push_back(R90);
        ret.push_back(R180);
        ret.push_back(R270);
        return ret;
    }
};

class Contest {
    public:
    Cell grid[5][5];
    std::vector<Ingredient> ingredients;
    int candidates;
    Contest() {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                grid[i][j] = Cell(0, WHITE);
            }
        }
        std::cin >> candidates;
        for(int i=0; i<candidates; i++) {
            Ingredient in = Ingredient();
            ingredients.push_back(in);
        }
        run();
    }
    void add(Ingredient in, Pos p) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                grid[p.x+i][p.y+j].quality += in.body[i][j].quality;
                if(grid[p.x+i][p.y+j].quality < 0) grid[p.x+i][p.y+j].quality = 0;
                if(grid[p.x+i][p.y+j].quality > 9) grid[p.x+i][p.y+j].quality = 9;
                if(in.body[i][j].element != WHITE) {
                    grid[p.x+i][p.y+j].element = in.body[i][j].element;
                }
            }
        }
    }
    int score() {
        int ret = 0;
        int arr[5] = {7, 5, 3, 2, 0};
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                ret += arr[grid[i][j].element] * grid[i][j].quality;
            }
        }
        return ret;
    }
    void run() {
        int max_value = INT32_MIN;
        for(int i=0; i<candidates; i++) {
            for(int j=0; j<candidates; j++) {
                for(int k=0; k<candidates; k++) {
                    // i, j, k번 재료 선택
                    // 중복된 재료 선택시 통과
                    if(i==j || j==k || i==k) continue;
                    auto first_rotates = ingredients[i].rotates();
                    auto second_rotates = ingredients[j].rotates();
                    auto third_rotates = ingredients[k].rotates();
                    for(int x=0; x<4; x++) {
                        for(int y=0; y<4; y++) {
                            for(int z=0; z<4; z++) {
                                // 각 재료를 x, y, z번 회전.
                                for(int a=0; a<4; a++) {
                                    for(int b=0; b<4; b++) {
                                        for(int c=0; c<4; c++) {
                                            // 각 재료의 위치 선정
                                            auto copy = *this;
                                            copy.add(first_rotates[x], standards[a]);
                                            copy.add(second_rotates[y], standards[b]);
                                            copy.add(third_rotates[z], standards[c]);
                                            max_value = std::max(max_value, copy.score());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << max_value << std::endl;
    }
};

int main() {
    Contest c = Contest();
}