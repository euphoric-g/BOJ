#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

class Array {
    public:
    int **data;
    int width;
    int height;
    bool cmp(const int &a, const int &b) { return a < b; }
    void operation() {
        if(width >= height) R();
        else C();
    }
    void R() {
        
    }
    void C() {

    }
    Array(){}
    Array(std::queue<int> e) {
        data = new int[3][3];
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                data[i][j] = e.front();
                e.pop();
            }
        }
        width = 3;
        height = 3;
    }
};

int main() {
    int r, c, k;
    std::cin >> r >> c >> k;
    std::queue<int> elements;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int element;
            std::cin >> element;
            elements.push(element);
        }
    }
    Array arr = Array(elements);
}