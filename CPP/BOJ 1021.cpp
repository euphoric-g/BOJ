#include <iostream>
#include <deque>
#include <vector>

#define LEFT 0
#define RIGHT 1

void operation(std::deque<int> &dq, int &cnt, int to_find) {
    std::deque<int> copy = dq;
    int index = 0;
    int left, right;
    while(copy[index] != to_find) {
        index++;
    }
    left = index;
    right = index == 0 ? 0 : copy.size() - left;
    // std::cout << "to_find = " << to_find << ", left, right = " << left << ", " << right << '\n';
    if(left <= right) {
        while(left-->0) {
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        }
        dq.pop_front();
    } else {
        while(right-->0) {
            dq.push_front(dq.back());
            dq.pop_back();
            cnt++;
        }
        dq.pop_front();
    }
}

int main() {
    int n, m;
    int count = 0;
    std::deque<int> dq;
    std::cin >> n >> m;
    for(int i=1; i<=n; i++) dq.push_back(i);
    for(int i=0; i<m; i++) {
        int to_find;
        std::cin >> to_find;
        operation(dq, count, to_find);
    }
    std::cout << count << '\n';
}