#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            int num;
            cin >> num;
            q.push({i+1, num});
        }
    }
    while(q.size() > 1) {
        // cout << "Pop {" << q.front().first << ", " << q.front().second << "}\n";
        auto get = q.front().second; q.pop();
        while(--get) {
            q.push(q.front()); q.pop();
        }
    }
    cout << q.front().first << ' ' << q.front().second << '\n';
}