#include <iostream>

#define START 0
#define DEST 32
#define DEFAULT 0
#define FIRST 1
#define ERROR -1

/*
START(0)
1
2
3
4
5   ----------------------------- 21
6                                 |
7                                 22
8                                 |
9                                 23
10  ------------------> 25        |
11                      ㄴ 26 --- 24 -- 30
12                                |     |
13                                29    |
14                                |     |
15  ------------------> 27 ------ 28    |
16                                      |
17                                      31
18                                      |
19                                      |
20  ------------------------------------J
DEST(32)
*/

int arr[10];
int mal_pos[] = {START, START, START, START};
int exist_mal[DEST+1] = {0, };
const int scoreboard[] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
    22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
    13, 16, 19, 25, 22, 24, 28, 27, 26, 30,
    35, 0
};

int next(int cur, bool is_start) {
    if(cur == 5 || cur == 10 || cur == 15) {
        if(is_start) {
            switch(cur) {
                case 5 :
                return 21;
                case 10:
                return 25;
                case 15:
                return 27;
            }
        } else {
            return cur + 1;
        }
    }
    if(cur <= 19) return cur+1;
    switch(cur) {
            case 21:
            return 22;
            case 22:
            return 23;
            case 23:
            return 24;
            case 25:
            return 26;
            case 26:
            return 24;
            case 27:
            return 28;
            case 28:
            return 29;
            case 29:
            return 24;
            case 24:
            return 30;
            case 30:
            return 31;
            case 31:
            return 20;
            case 20:
            return DEST;
            case DEST:
            return DEST;
    }
    return ERROR;
}

std::pair<bool, int> move_check(int mal_num, int dice) {
    int temp_pos = mal_pos[mal_num];
    int d = dice;
    temp_pos = next(temp_pos, true);
    for(int i=0; i<d-1; i++) temp_pos = next(temp_pos, false);
    if(exist_mal[temp_pos] > 0 && temp_pos != DEST) return std::pair<bool, int>(false, ERROR);
    return std::pair<bool, int>(true, temp_pos);
}

int main() {
    int max_score = 0;
    for(int i=0; i<10; i++) std::cin >> arr[i];
    for(int i=0; i<(1 << 20); i++) {
        for(int z=START; z<=DEST; z++) {
            exist_mal[z] = 0;
        }
        exist_mal[0] = 4;
        for(int z=0; z<4; z++) {
            mal_pos[z] = START;
        }
        int val = i;
        int temp_score = 0;
        bool flag = true;
        for(int j=0; j<10 && flag; j++) {
            int selected_mal = val % 4;
            val /= 4;
            if(mal_pos[selected_mal] != DEST) {
                auto next = move_check(selected_mal, arr[j]);
                if(next.first) {
                    exist_mal[mal_pos[selected_mal]]--;
                    mal_pos[selected_mal] = next.second;
                    exist_mal[mal_pos[selected_mal]]++;
                    temp_score += scoreboard[mal_pos[selected_mal]];
                } else {
                    flag = false;
                }
            } else {
                flag = false;
            }
        }
        max_score = std::max(max_score, temp_score);
    }
    std::cout << max_score << '\n';
}