#include <iostream>
#include <string>
#include <list>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        std::string str;
        std::cin >> str;
        std::list<char> pwlist;
        auto cur = pwlist.begin();
        for(const auto &ch : str) {
            if(ch == '<') {
                if(cur != pwlist.begin()) cur--;
                // cur--;
            } else if(ch == '>') {
                if(cur != pwlist.end()) cur++;
                // cur++;
            } else if(ch == '-') {
                if(cur != pwlist.begin()) cur = pwlist.erase(--cur);
            } else {
                cur = pwlist.insert(cur, ch);
                cur++;
            }
        }
        std::string pw;
        for(auto i = pwlist.begin(); i != pwlist.end(); i++) {
            pw += *i;
        }
        std::cout << pw << '\n';
    }
    return 0;
}