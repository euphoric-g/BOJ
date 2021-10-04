#include <iostream>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int s;
    cin >> s;
    queue<pair<int, int>> q;
    map<pair<int, int>, int> memo;
    q.push({1, 0});
    int time = 0;
    while(!q.empty()) {
        int sz = q.size();
        time++;
        while(sz--) {
            auto cur = q.front(); q.pop();
            if(cur.first == s) {
                cout << time-1 << '\n';
                return 0;
            }
            if(memo[{cur.first, cur.first}] == 0) {
                memo[{cur.first, cur.first}] = time;
                q.push({cur.first, cur.first});
            }
            if(memo[{cur.first + cur.second, cur.second}] == 0) {
                memo[{cur.first + cur.second, cur.second}] = time;
                q.push({cur.first + cur.second, cur.second});
            }
            if(memo[{max(0, cur.first-1), cur.second}] == 0) {
                memo[{max(0, cur.first-1), cur.second}] = time;
                q.push({max(0, cur.first-1), cur.second});
            }
        }
    }
}