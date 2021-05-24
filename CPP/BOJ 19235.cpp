#include <iostream>
#include <queue>
#include <vector>

#define BLANK false
#define BLOCK true

#define B0 9
#define G0 9
#define B1 8
#define G1 8
#define B2 7
#define G2 7
#define B3 6
#define G3 6
#define BU0 5
#define GU0 5
#define BU1 4
#define GU1 4

// type 1   #

// type 2   ##

// type 3   #
//          #

/*
   +-----+-------+-------+
   | RED | BLUE  |  BLUE |
   |     | UPPER |       |
   +-----+-------+-------+
   |GREEN|
   |UPPER|
   +-----+
   |GREEN|
   +-----+
*/
bool arr[10][10];

auto check_green_upper_zero = []() -> bool { return arr[GU0][0] || arr[GU0][1] || arr[GU0][2] || arr[GU0][3]; };
auto check_green_upper_one = []() -> bool { return arr[GU1][0] || arr[GU1][1] || arr[GU1][2] || arr[GU1][3]; };
auto check_blue_upper_zero = []() -> bool { return arr[0][BU0] || arr[1][BU0] || arr[2][BU0] || arr[3][BU0]; };
auto check_blue_upper_one = []() -> bool { return arr[0][BU1] || arr[1][BU1] || arr[2][BU1] || arr[3][BU1]; };
auto check_blue_complete = [](int ind) -> bool { return arr[0][ind] && arr[1][ind] && arr[2][ind] && arr[3][ind]; };
auto check_green_complete = [](int ind) -> bool { return arr[ind][0] && arr[ind][1] && arr[ind][2] && arr[ind][3]; };
auto check_green_any = []() -> bool { return check_green_complete(G0) || check_green_complete(G1) || check_green_complete(G2) || check_green_complete(G3); };
auto check_blue_any = []() -> bool { return check_blue_complete(B0) || check_blue_complete(B1) || check_blue_complete(B2) || check_blue_complete(B3); };
auto remove_block_green = [](int ind) { arr[ind][0] = BLANK, arr[ind][1] = BLANK, arr[ind][2] = BLANK, arr[ind][3] = BLANK; };
auto remove_block_blue = [](int ind) { arr[0][ind] = BLANK, arr[1][ind] = BLANK, arr[2][ind] = BLANK, arr[3][ind] = BLANK; };
auto bti = [](bool b) -> int { if(b) return 1; else return 0; };
auto fall_down_green = [](int ind) {
    for(int i = ind; i >= GU1; i--) {
        for(int j=0; j<4; j++) {
            arr[i+1][j] = arr[i][j];
        }
    }
};
auto fall_down_blue = [](int ind) {
    for(int i=ind; i >= BU1; i--) {
        for(int j=0; j<4; j++) {
            arr[j][i+1] = arr[j][i];
        }
    }
};
auto show = []() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            if(i>3 && j>3) std::cout << ' ';
            else std::cout << arr[i][j] ? '#' : '.';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, score = 0;
    std::cin >> n;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            arr[i][j] = BLANK;
        }
    }
    while(n-->0) {
        int t, x, y, xx, yy;
        std::cin >> t >> x >> y;
        // 블록 이동
        if(t == 1) {
            int to_right = y;
            int to_down = x;
            while(1) {
                if(to_right == B0) break;
                if(arr[x][to_right+1] == BLANK) to_right++;
                else break;
            }
            while(1) {
                if(to_down == G0) break;
                if(arr[to_down+1][y] == BLANK) to_down++;
                else break;
            }
            arr[x][to_right] = BLOCK;
            arr[to_down][y] = BLOCK;
        } else if(t == 2) {
            // ##
            xx = x; yy = y+1;
            int to_right = y+1;
            int to_down = x;
            // 오른쪽 이동
            while(1) {
                if(to_right == B0) break;
                if(arr[x][to_right+1] == BLANK) to_right++;
                else break;
            }
            arr[x][to_right] = BLOCK;
            arr[x][to_right-1] = BLOCK;
            // 아래쪽 이동
            while(1) {
                if(to_down == G0) break;
                if(arr[to_down+1][y] == BLANK && arr[to_down+1][y+1] == BLANK) to_down++;
                else break;
            }
            arr[to_down][y] = BLOCK;
            arr[to_down][y+1] = BLOCK;
        } else if(t == 3) {
            xx = x+1; yy = y;
            int to_right = y;
            int to_down = x+1;
            // 오른쪽 이동
            while(1) {
                if(to_right == B0) break;
                if(arr[x][to_right+1] == BLANK && arr[x+1][to_right+1] == BLANK) to_right++;
                else break;
            }
            arr[x][to_right] = BLOCK;
            arr[x+1][to_right] = BLOCK;
            // 아래쪽 이동
            while(1) {
                if(to_down == G0) break;
                if(arr[to_down+1][y] == BLANK) to_down++;
                else break;
            }
            arr[to_down][y] = BLOCK;
            arr[to_down-1][y] = BLOCK;
        }
        // 완성된 칸 확인
        if(check_blue_any()) {
            int ind = B0;
            while(ind >= BU1) {
                if(check_blue_complete(ind)) {
                    score++;
                    remove_block_blue(ind);
                    fall_down_blue(ind-1);
                    ind = B0 + 1;
                }
                ind--;
            }
        }
        if(check_green_any()) {
            int ind = G0;
            while(ind >= GU1) {
                if(check_green_complete(ind)) {
                    score++;
                    remove_block_green(ind);
                    fall_down_green(ind-1);
                    ind = B0 + 1;
                }
                ind--;
            }
        }
        // 연한 초록, 연한 파랑칸 체크 -> 있으면 아랫줄 제거 후 이동
        int blue_upper = bti(check_blue_upper_zero()) + bti(check_blue_upper_one());
        int green_upper = bti(check_green_upper_zero()) + bti(check_green_upper_one());
        while(blue_upper-->0) {
            // 한칸 지우고 이동
            remove_block_blue(B0);
            fall_down_blue(B1);
            remove_block_blue(BU1);
        }
        while(green_upper-->0) {
            remove_block_green(G0);
            fall_down_green(B1);
            remove_block_green(GU1);
        }
    }
    std::cout << score << '\n';
    int block_cnt = 0;
    for(int i=6; i<=9; i++) {
        for(int j=0; j<4; j++) {
            if(arr[j][i]) block_cnt++;
            if(arr[i][j]) block_cnt++;
        }
    }
    std::cout << block_cnt << '\n';
    return 0;
}