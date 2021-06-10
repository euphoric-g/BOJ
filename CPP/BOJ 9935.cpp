#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::string str, explosive;
    std::cin >> str >> explosive;
    int strlen = str.size(), explosive_len = explosive.size();
    std::stack<char> st;
    for(int i=0; i<strlen; i++) {
        st.push(str[i]);
        if(st.size() >= explosive_len) {
            // explode
            std::stack<char> tmp;
            bool exit = false;
            int ind = explosive_len;
            while(ind--) {
                if(st.top() != explosive[ind]) {
                    exit = true;
                    break;
                } else {
                    tmp.push(st.top());
                    st.pop();
                }
            }
            if(exit) {
                while(!tmp.empty()) {
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
        }
    }
    if(st.empty()) {
        std::cout << "FRULA\n";
        return 0;
    }
    std::string ans = "";
    while(!st.empty()) {
        ans += st.top(); st.pop();
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << '\n';
}