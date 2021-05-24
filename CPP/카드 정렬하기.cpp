#include <iostream>
#include <queue>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i=0; i<n; i++) {
        int size;
        std::cin >> size;
        pq.push(size);
    }
    int cmps = 0;
    while(pq.size() > 1) {
        int s1 = pq.top(); pq.pop();
        int s2 = pq.top(); pq.pop();
        cmps += s1 + s2;
        pq.push(s1+s2);
    }
    std::cout << cmps << std::endl;
}