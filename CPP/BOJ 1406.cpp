#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str;
    int m;
    cin >> str >> m;
    deque<char> s;
    deque<char> q;
    for(int i=0; i<str.size(); i++) s.push_back(str[i]);
    while(m--) {
        char c, x;
        cin >> c;
        if(c == 'L') {
            if(!s.empty()) {
                q.push_front(s.back());
                s.pop_back();
            }
        } else if(c == 'D') {
            if(!q.empty()) {
                s.push_back(q.front());
                q.pop_front();
            }
        } else if(c == 'B') {
            if(!s.empty()) s.pop_back();
        } else if(c == 'P') {
            cin >> x;
            s.push_back(x);
        }
    }
    string ans;
    for(int i=0; i<s.size(); i++) ans.push_back(s[i]);
    for(int i=0; i<q.size(); i++) ans.push_back(q[i]);
    cout << ans << '\n';
}