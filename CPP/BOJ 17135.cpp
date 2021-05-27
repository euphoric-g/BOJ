#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ENEMY 1
#define BLANK 0

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

class Castle {
    public:
    int castle[16][16];
    int range;
    int n, m;
    Castle() {
        std::cin >> n >> m >> range;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                std::cin >> castle[i][j];
            }
        }
        for(int i=0; i<m; i++) castle[n][i] = BLANK;
    }
    bool exist_enemy() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(castle[i][j] == ENEMY) return true;
            }
        }
        return false;
    }
    bool pos_check(std::pair<int, int> p) {
        return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
    }
    std::pair<int, int> target(int archer) {
        std::queue<std::pair<int, int>> q;
        bool visited[16][16];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<m; j++) {
                visited[i][j] = false;
            }
        }
        q.push({n, archer});
        visited[n][archer] = true;
        int dist = -1;
        while(!q.empty()) {
            if(++dist > range) return {-1, -1};
            int sz = q.size();
            while(sz-->0) {
                auto get = q.front(); q.pop();
                if(castle[get.first][get.second] == ENEMY) return get;
                for(int d=0; d<4; d++) {
                    std::pair<int, int> next = {get.first + dx[d], get.second + dy[d]};
                    if(pos_check(next) && !visited[next.first][next.second]) {
                        visited[next.first][next.second] = true;
                        q.push(next);
                    }
                }
            }
        }
        return {-1, -1};
    }
    int run(int a, int b, int c) {
        int score = 0;
        while(exist_enemy()) {
            auto list = {target(a), target(b), target(c)};
            for(const auto &item : list) {
                if(!(item.first == -1 && item.second == -1)) {
                    if(castle[item.first][item.second] == ENEMY) {
                        score++;
                        castle[item.first][item.second] = BLANK;
                    }
                }
            }
            for(int i=n-2; i>=0; i--) {
                for(int j=0; j<m; j++) {
                    castle[i+1][j] = castle[i][j];
                }
            }
            for(int i=0; i<m; i++) castle[0][i] = BLANK;
        }
        return score;
    }
    void bruteforce() {
        int max_score = 0;
        for(int i=0; i<m; i++) {
            for(int j=i+1; j<m; j++) {
                for(int k=j+1; k<m; k++) {
                    Castle copy = *this;
                    max_score = std::max(max_score, copy.run(i, j, k));
                }
            }
        }
        std::cout << max_score << '\n';
    }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    Castle c = Castle();
    c.bruteforce();
    return 0;
}