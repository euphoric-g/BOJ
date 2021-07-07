#include <iostream>
#include <map>
#include <vector>

#define INSERT 'I'
#define DELETE 'D'
#define MAX 1
#define MIN -1

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        std::map<int, int> dict;
        int k;
        std::cin >> k;
        while(k--) {
            char op;
            int n;
            std::cin >> op >> n;
            if(op == INSERT) {
                dict[n]++;
            } else if(op == DELETE) {
                if(dict.empty()) continue;
                if(n == MAX) {
                    if(--(dict.rbegin()->second) <= 0) dict.erase(dict.rbegin()->first);
                } else if(n == MIN) {
                    if(--(dict.begin()->second) <= 0) dict.erase(dict.begin()->first);
                }
            }
        }
        if(dict.empty()) {
            std::cout << "EMPTY\n";
        } else {
            std::cout << dict.rbegin()->first << ' ' << dict.begin()->first << '\n';
        }
    }
}