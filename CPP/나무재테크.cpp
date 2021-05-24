#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <iterator>

#define         MAX_SIZE        10
#define         ALIVE           0
#define         DEAD            1
#define         END             2

class Pos {
    public:
    int x, y;
    void set_size(int a, int b) { x = a; y = b; }
    int get_x() {return x;}
    int get_y() {return y;}
};

class Tree {
    public:
    Pos position;
    int age;
    int stat;
    Tree(){}
    Tree(Pos p, int a) { position = p; age = a; stat = ALIVE; }
    void fall() {

    }
};

bool cmp (Tree a, Tree b) {
    return a.age < b.age;
}

void grow(void *, Pos p);

class Cell {
    private:
    void *super; // Field *
    public:
    Pos position;
    std::deque<Tree> trees;
    int food;
    void add_tree(int age) {
        trees.push_front(Tree(position, age));
    }
    void add_food(int val) { food += val; }
    Cell(){}
    Cell(void *ptr, int x, int y) {
        super = ptr;
        position.set_size(x, y);
        food = 5;
    }
    void spring_func() {
        for(int i=0; i<trees.size(); i++) {
            if(trees[i].stat != ALIVE) continue;
            if(food >= trees[i].age) {
                food -= trees[i].age++;
            } else {
                trees[i].stat = DEAD;
            }
        }
    }
    void summer_func() {
        for(int i=0; i<trees.size(); i++) {
            if(trees[i].stat == DEAD) {
                trees[i].stat = END;
                add_food(trees[i].age / 2);
            }
        }
        std::deque<Tree> temp;
        for(int i=0; i<trees.size(); i++) {
            if(trees[i].stat == ALIVE) temp.push_back(trees[i]);
        }
        trees = temp;
    }
    void autumn_func() {
        for(int i=0; i<trees.size(); i++) {
            if(trees[i].stat == ALIVE && trees[i].age % 5 == 0) {
                grow(super, position);
            }
        }
    }
};

class Field {
    private:
    bool valid_position(Pos p) {
        if(p.get_x() >= 0 && p.get_x() < size && p.get_y() >= 0 && p.get_y() < size) return true;
        else return false;
    }
    public:
    int size;
    Cell field[MAX_SIZE][MAX_SIZE];
    int food_matrix[MAX_SIZE][MAX_SIZE];
    Field(){}
    Field(int sz) {
        size = sz;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                field[i][j] = Cell(this, i, j);
            }
        }
    }
    void spring() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                field[i][j].spring_func();
            }
        }
    }
    void summer() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                field[i][j].summer_func();
            }
        }
    }
    void autumn() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                field[i][j].autumn_func();
            }
        }
    }
    void winter() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                field[i][j].add_food(food_matrix[i][j]);
            }
        }
    }
    void grow(Pos p) {
        const int xdiff[] = {-1, 0, 1};
        const int ydiff[] = {-1, 0, 1};
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i == 1 && j == 1) continue;
                Pos t;
                t.set_size(p.get_x() + xdiff[i], p.get_y() + ydiff[j]);
                if(valid_position(t)) {
                    field[t.get_x()][t.get_y()].add_tree(1);
                }
            }
        }
    }
};

void grow(void *ptr, Pos p) {
    Field *pt = (Field *)ptr;
    pt->grow(p);
}

void print_data(Field f) {
    int trees_cnt = 0;
    for(int i=0; i<f.size; i++) {
        for(int j=0; j<f.size; j++) {
            for(int k=0; k<f.field[i][j].trees.size(); k++) {
                if(f.field[i][j].trees[k].stat == ALIVE) trees_cnt++;
            }
        }
    }
    std::cout << trees_cnt << std::endl;
}

void print_detail(Field f, int k) {
    std::cout << "YEAR " << k << std::endl;
    for(int i=0; i < f.size; i++) {
        for(int j=0; j<f.size; j++) {
            std::string str = "[";
            for(int k=0; k<f.field[i][j].trees.size(); k++) {
                str += std::to_string(f.field[i][j].trees[k].age);
                str += ((f.field[i][j].trees[k].stat == ALIVE) ? "A" : "D");
                str += ", ";
            }
            str += "] ";
            std::cout << str;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    Field f = Field(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> f.food_matrix[i][j];
        }
    }
    for(int i=0; i<m; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        f.field[x-1][y-1].add_tree(z);
    }
    for(int i=0; i<k; i++) {
        f.spring();
        f.summer();
        f.autumn();
        f.winter();
        // print_detail(f, i);
    }
    print_data(f);
}