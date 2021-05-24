#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

typedef std::pair<int, int> Time;

bool cmp (const Time &a, const Time &b) {
    return a.first > b.first;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<Time> vt;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i=0; i<n; i++) {
        int s, t;
        std::cin >> s >> t;
        vt.push_back(Time(s, t));
    }
    std::sort(vt.begin(), vt.end(), cmp);
    while(!vt.empty()) {
        Time get = vt.back(); vt.pop_back();
        if(pq.empty() || pq.top() > get.first) {
            pq.push(get.second);
        } else {
            pq.pop();
            pq.push(get.second);
        }
    }
    std::cout << pq.size() << std::endl;
}