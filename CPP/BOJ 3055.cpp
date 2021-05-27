#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define BLANK '.'
#define WATER '*'
#define STONE 'X'
#define CAVE 'D'
#define HEDGEHOG 'S'

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    int r, c;
    std::cin >> r >> c;
    char map[51][51];
    bool visited[51][51];
    for(int i=0; i<r; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<c; j++) {
            map[i][j] = str[j];
            visited[i][j] = false;
        }
    }
}