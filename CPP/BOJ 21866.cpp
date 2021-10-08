#include <iostream>
#include <vector>
#include <string>

#define NONE 0
#define DRAW 1
#define HACKER 2

const std::string str[] = { "none\n", "draw\n", "hacker\n" };

int main() {
    std::vector<int> max_score = {100, 100, 200, 200, 300, 300, 400, 400, 500};
    std::vector<int> arr(9, 0);
    for(int i=0; i<9; i++) {
        std::cin >> arr[i];
    }
    int state = NONE;
    int sum = 0;
    for(int i=0; i<9 && state == NONE; i++) {
        if(arr[i] > max_score[i]) {
            state = HACKER;
            continue;
        } else {
            sum += arr[i];
            if(sum >= 100) {
                state = DRAW;
                continue;
            }
        }
    }
    std::cout << str[state];
    return 0;
}