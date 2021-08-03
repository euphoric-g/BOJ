#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    std::string sin;
    std::cin >> sin;
    for(int i=1; i<=3; i++) {
        if(sin.size() < i) continue;
        int start = std::stoi(sin.substr(0, i));
        int cur = start;
        std::string made;
        while(made.size() < sin.size()) {
            made += std::to_string(cur++);
        }
        if(sin == made) {
            std::cout << start << ' ' << cur-1 << '\n';
            return 0;
        }
    }
}