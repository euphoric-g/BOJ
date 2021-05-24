#include <iostream>
#include <algorithm>

#define DISTRICT_NOT_DEFINED -1

class Cell {
    public:
    int population;
    int district;
    Cell(int p) { population = p; district = DISTRICT_NOT_DEFINED; }
};

class City {
    public:
    int size;
    Cell **grid;
    int cnt_district[5];
    City(){}
    City(int n) {
        size = n;
        grid = new Cell[n][n];
        for(int i=0; i<5; i++) cnt_district[i] = 0;
    }
    void free() { delete[] grid; }
    bool valid() {
        int flag = 1;
        for(int i=0; i<5; i++) flag *= cnt_district[i];
        return (flag != 0 ? true : false);
    }
    int calc_district(int x, int y, int d1, int d2, int r, int c) {
        if(0 <= r < x+d1-1 && 0 <= c <= y-1) {
            cnt_district[0]++;
            return 1;
        } else if(0 <= r <= x+d2-1 && y-1 < c <= size-1) {
            cnt_district[1]++;
            return 2;
        } else if(x+d1-1 <= r <= size-1 && 0 <= c < y-d1+d2-1) {
            cnt_district[2]++;
            return 3;
        } else if( x+d2-1 < r <= size-1 && y-d1+d2-1 <= c <= size-1) {
            cnt_district[3]++;
            return 4;
        } else {
            cnt_district[4]++;
            return 5;
        }
    }
    void set_district(int x, int y, int d1, int d2) {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                grid[i][j].district = calc_district(x, y, d1, d2, i, j);
            }
        }
    }
    int divide() {
        for(int x=1; x<size; x++) {
            for(int y = 1; y < size; y++) {
                for(int d1 = 1; d1 < size; d1++) {
                    for(int d2 = 1; d2 < size; d2++) {
                        
                    }
                }
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    City jaehyeon = City(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int arc;
            std::cin >> arc;
            jaehyeon.grid[i][j] = Cell(arc);
        }
    }
}