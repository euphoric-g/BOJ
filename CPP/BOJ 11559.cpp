#include <iostream>
#include <string>
#include <queue>

#define FASTIO

#define BLANK '.'
#define RED 'R'
#define GREEN 'G'
#define BLUE 'B'
#define PURPLE 'P'
#define YELLOW 'Y'

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

auto is_puyo = [](char c) -> bool { return c != BLANK; };
auto pos_check = [](const std::pair<int, int> &pos) -> bool {
    return pos.first >= 0 && pos.first < 12 && pos.second >= 0 && pos.second < 6;
};

char field[12][6];
bool visited[12][6];

int main() {
#ifdef FASTIO
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
#endif
    for(int i=0; i<12; i++) {
        std::string str;
        std::cin >> str;
        for(int j=0; j<6; j++) {
            field[i][j] = str[j];
            visited[i][j] = false;
        }
    }
    auto show = [](){
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                std::cout << field[i][j];
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    };
    auto clear_all = [](){ for(int i=0; i<12; i++) for(int j=0; j<6; j++) visited[i][j] = false; };
    int chain = 0;
    while(1) {
        clear_all();
        bool explode = false;
        std::vector<std::vector<std::pair<int, int>>> explode_puyos;
        for(int i=0; i<12; i++) {
            for(int j=0; j<6; j++) {
                if(is_puyo(field[i][j]) && !visited[i][j]) {
                    // 탐색 시작, 4개 이상 뭉쳐있으면 폭발 대상
                    std::queue<std::pair<int, int>> q;
                    std::vector<std::pair<int, int>> puyos;
                    q.push({i, j});
                    puyos.push_back({i, j});
                    visited[i][j] = true;
                    int chunk_size = 0;
                    while(!q.empty()) {
                        int sz = q.size();
                        while(sz--) {
                            auto get = q.front(); q.pop();
                            chunk_size++;
                            for(int d=0; d<4; d++) {
                                int nx = get.first + dx[d], ny = get.second + dy[d];
                                if(pos_check({nx, ny}) && !visited[nx][ny] && field[nx][ny] == field[i][j]) {
                                    visited[nx][ny] = true;
                                    puyos.push_back({nx, ny});
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                    if(chunk_size > 3) {
                        explode = true;
                        explode_puyos.push_back(puyos);
                    }
                }
            }
        }
        if(explode) {
            // explode
            chain++;
            for(const auto &chunk : explode_puyos) {
                for(const auto &block : chunk) {
                    field[block.first][block.second] = BLANK;
                }
            }
            // fall
            for(int i=11; i>=0; i--) {
                for(int j=0; j<6; j++) {
                    if(is_puyo(field[i][j])) {
                        std::pair<int, int> cur = {i, j};
                        while(pos_check({cur.first+1, cur.second}) && field[cur.first+1][cur.second] == BLANK) {
                            field[cur.first+1][cur.second] = field[cur.first][cur.second];
                            field[cur.first][cur.second] = BLANK;
                            cur = {cur.first+1, cur.second};
                        }
                    }
                }
            }
            // show();
        } else break;
    }
    std::cout << chain << '\n';
    return 0;
}