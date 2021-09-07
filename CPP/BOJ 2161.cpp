#include <iostream>
#include <deque>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::deque<int> dq;
    std::queue<int> q;
    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }
    while(dq.size() > 0) {
        q.push(dq.front());
        dq.pop_front();
        if(dq.empty()) break;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    while(!q.empty()) {
        std::cout << q.front();
        q.pop();
        std::cout << (q.empty() ? '\n' : ' ');
    }
}