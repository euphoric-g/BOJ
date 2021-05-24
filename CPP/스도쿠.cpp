#include <iostream>
#include <algorithm>
#include <vector>

class Board {
    public:
    int arr[9][9];
    Board() {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char in;
                std::cin >> in;
                arr[i][j] = in - '0';
            }
        }
    }
    std::vector<int> recommend(int r, int c) {
        bool check_arr[10];
        for(int i=0; i<10; i++) check_arr[i] = true;
        std::vector<int> ret;
        if(arr[r][c] == 0) {
            for(int i=0; i<9; i++) {
                if(arr[r][i] != 0) {
                    check_arr[arr[r][i]] = false;
                }
                if(arr[i][c] != 0) {
                    check_arr[arr[i][c]] = false;
                }
            }
            for(int i=3*(r/3); i<3*(r/3)+3; i++) {
                for(int j=3*(c/3); j<3*(c/3)+3; j++) {
                    if(arr[i][j] != 0) {
                        check_arr[arr[i][j]] = false;
                    }
                }
            }
            for(int i=1; i<=9; i++) {
                if(check_arr[i]) ret.push_back(i);
            }
            for(int i=1; i<=9; i++) {
            }
            return ret;
        } else {
            return ret;
        }
    }
    bool check() {
        int check_arr[10] = {0, };
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(++check_arr[arr[i][j]] > i+1 && arr[i][j] != 0) {
                    return false;
                }
            }
        }
        for(int i=0; i<10; i++) check_arr[i] = 0;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(++check_arr[arr[j][i]] >i+1 && arr[j][i] != 0) return false;
            }
        }
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int check_temp[10] = {0, };
                for(int k=3*i; k<3*(i+1); k++) {
                    for(int l=3*j; l<3*(j+1); l++) {
                        if(++check_temp[arr[k][l]] > 1 && arr[i][j] != 0) return false;
                    }
                }
            }
        }
        return true;
    }
    void show() {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                std::cout << arr[i][j];
            }
            std::cout << std::endl;
        }
    }
    bool backtracking() {
        Board copied = *this;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(copied.arr[i][j] == 0) {
                    std::vector<int> recommends = copied.recommend(i, j);
                    if(recommends.size() == 0) return false;
                    for(const auto& rec : recommends) {
                        copied.arr[i][j] = rec;
                        if(copied.backtracking()) {
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
        if(copied.check()) {
            show();
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Board b = Board();
    b.backtracking();
    return 0;
}