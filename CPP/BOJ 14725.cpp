#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

class Trie {
    public:
    bool finish;
    std::string name;
    std::map<std::string, Trie> next;
    Trie() {}
    Trie(std::string n) { finish = false; name = n; }
    void insert(std::queue<std::string> &route) {
        if(route.empty()) {
            finish = true;
            return;
        }
        std::string get = route.front(); route.pop();
        if(next.find(get) == next.end()) {
            next[get] = Trie(get);
        }
        next[get].insert(route);
    }
    void explore(int depth) {
        if(depth >= 0) std::cout << std::string(2*depth, '-') << name << '\n';
        for(auto &item : next) {
            item.second.explore(depth+1);
        }
    }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    Trie root = Trie();
    while(n--) {
        int k;
        std::cin >> k;
        std::queue<std::string> inputs;
        for(int i=0; i<k; i++) {
            std::string str;
            std::cin >> str;
            inputs.push(str);
        }
        root.insert(inputs);
    }
    root.explore(-1);
}