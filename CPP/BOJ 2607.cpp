#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string standard;

bool compare(string s) {
    // 같은 구성
    sort(s.begin(), s.end());
    if(standard == s) return true;
    if(standard.size() - s.size() == 1) {
        // 하나 더하기
        for(char c = 'A'; c <= 'Z'; c++) {
            string copy = s;
            copy += c;
            sort(copy.begin(), copy.end());
            if(standard == copy) return true;
        }
    } else if(s.size() - standard.size() == 1) {
        // 하나 빼기
        for(int i=0; i<s.size(); i++) {
            string tmp = s.substr(0, i) + s.substr(i+1, s.size());
            if(standard == tmp) return true;
        }
    } else if(s.size() == standard.size()) {
        // 하나 바꾸기
        for(int i=0; i<s.size(); i++) {
            for(char c = 'A'; c <= 'Z'; c++) {
                string copy = s;
                copy[i] = c;
                sort(copy.begin(), copy.end());
                if(standard == copy) return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(i == 0) {
            standard = s;
            sort(standard.begin(), standard.end());
        }
        else {
            if(compare(s)) ++cnt;
        }
    }
    cout << cnt << '\n';
}