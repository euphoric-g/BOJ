#include <iostream>
#include <algorithm>
#include <queue>

typedef long long ll;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    for(int i=0; i<n; i++) {
        ll num;
        std::cin >> num;
        pq.push(num);
    }
    while(m-->0) {
        ll m1 = pq.top(); pq.pop();
        ll m2 = pq.top(); pq.pop();
        pq.push(m1+m2); pq.push(m1+m2);
    }
    ll sum = 0;
    while(!pq.empty()) {
        sum += pq.top(); pq.pop();
    }
    std::cout << sum << std::endl;
}