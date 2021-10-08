#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iterator>

#define BAD_CASE 0
#define GOOD 0

char **board;
bool **visit_check;
int alphabets[30] = {0, };
std::pair<int, int> last_node;
int r, c;
int depth = 1;
int ret = 0;
const int xdif[4] = { 0, 0, -1, 1};
const int ydif[4] = { 1, -1, 0, 0};

bool check(std::pair<int, int> pos) {
    return pos.first >= 0 && pos.first < r && pos.second >= 0 && pos.second < c && !visit_check[pos.first][pos.second];
}

int backtracking() {
    for(int i=0; i<30; i++) if(alphabets[i] > 1) return BAD_CASE;
    ret = std::max(ret, depth);
    std::pair<int, int> cur = last_node;
    for(int i=0; i<4; i++) {
        std::pair<int, int> next = std::pair<int, int>(cur.first + xdif[i], cur.second + ydif[i]);
        if(check(next) && alphabets[board[next.first][next.second]-'A'] < 1) {
            depth++;
            visit_check[next.first][next.second] = true;
            alphabets[board[next.first][next.second]-'A']++;
            last_node = next;
            backtracking();
            depth--;
            visit_check[next.first][next.second] = false;
            alphabets[board[next.first][next.second]-'A']--;
            last_node = cur;
        }
    }
    return GOOD;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> r >> c;
    board = new char*[r];
    visit_check = new bool*[r];
    for(int i=0; i<r; i++) {
        board[i] = new char[c];
        visit_check[i] = new bool[c];
        for(int j=0; j<c; j++) {
            std::cin >> board[i][j];
            visit_check[i][j] = false;
        }
    }
    visit_check[0][0] = true;
    alphabets[board[0][0]-'A'] = 1;
    last_node = std::pair<int, int>(0, 0);
    backtracking();
    std::cout << ret << std::endl;
    delete[] board;
    delete[] visit_check;
    return 0;
}