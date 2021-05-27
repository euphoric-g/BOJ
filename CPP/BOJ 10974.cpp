#include <iostream>
#include <vector>

int n;
std::vector<int> bt;
bool selected[10];

void backtracking(int d) {
    if(d == n) {
        for(const auto &item : bt) std::cout << item << ' ';
        std::cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!selected[i]) {
            selected[i] = true;
            bt.push_back(i);
            backtracking(d+1);
            bt.pop_back();
            selected[i] = false;
        }
    }
}

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin >> n;
    backtracking(0);
    return 0;
}