#include <iostream>
#include <string>

using namespace std;

int n;
bool _find = false;

void fn(string cur) {
    if(_find) return;
    if(cur.size() == n) {
       _find = true;
       cout << cur << '\n';
       return;
    } else {
        for(int i=1; i<=3; i++) {
            cur += to_string(i);
            bool good = true;
            for(int j=1; j<=cur.size()/2 && good; j++) {
                if(cur.substr(cur.size()-j, j) == cur.substr(cur.size()-2*j, j)) good = false;
            }
            if(good) fn(cur);
            cur.pop_back();
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    fn("1"); fn("2"); fn("3");
}