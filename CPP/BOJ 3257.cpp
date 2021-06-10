#include <iostream>
#include <string>
#include <queue>
#include <tuple>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::string s1, s2, sum;
    std::cin >> s1 >> s2 >> sum;
    bool visited[151][151];
    for(int i=0; i<151; i++) {
        for(int j=0; j<151; j++) visited[i][j] = false;
    }
    std::queue<std::tuple<int, int, std::string>> q;
    if(s1[0] == sum[0]) {
        visited[1][0] = true;
        q.push(std::make_tuple(1, 0, "1"));
    }
    if(s2[0] == sum[0]) {
        visited[0][1] = true;
        q.push(std::make_tuple(0, 1, "2"));
    }
    int cursor = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int a, b;
            std::string cur;
            std::tie(a, b, cur) = q.front(); q.pop();
            if(a == s1.size() && b == s2.size()) {
                std::cout << cur << '\n';
                return 0;
            }
            if(a < s1.size() && !visited[a+1][b] && s1[a] == sum[cursor]) {
                q.push(std::make_tuple(a+1, b, cur+"1"));
                visited[a+1][b] = true;
            }
            if(b < s2.size() && !visited[a][b+1] && s2[b] == sum[cursor]) {
                q.push(std::make_tuple(a, b+1, cur+"2"));
                visited[a][b+1] = true;
            }
        }
        cursor++;
    }
}