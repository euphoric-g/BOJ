// c++2a
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, x;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, decltype(
        [](const int &a, const int &b) { return a > b; }
    )> pq;
    while(n-->0) {
        std::cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                std::cout << "0\n";
                continue;
            }
            std::cout << pq.top() << '\n';
            pq.pop();
        } else {
            pq.push(x);
        }
    }
    return 0;
}