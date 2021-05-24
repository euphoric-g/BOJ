#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::queue<int> q;
    for(int i=1; i<=n; i++) q.push(i);
    while(q.size() > 1) {
        std::queue<int> qq;
        bool flag = true;
        while(!q.empty()) {
            if(!flag) qq.push(q.front());
            q.pop();
            flag = !flag;
        }
        q = qq;
    }
    std::cout << q.front() << '\n';
    return 0;
}