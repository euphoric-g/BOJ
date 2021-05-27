#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> pair;
typedef std::vector<pair> pair_vec;
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    std::priority_queue<pair, pair_vec, decltype([](const pair &a, const pair &b) -> bool {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    })> gems;
    // {무게, 가격}, 무게가 낮은 순서대로 정렬됨, 무게가 같으면 가격이 낮은 순서대로 정렬
    std::vector<int> bags(k, 0);
    for(int i=0; i<n; i++) {
        int m, v;
        std::cin >> m >> v;
        gems.push({m, v});
    }
    for(int i=0; i<k; i++) {
        std::cin >> bags[i];
    }
    std::sort(bags.begin(), bags.end());
    unsigned long long value = 0;
    std::priority_queue<pair, pair_vec, decltype([](const pair &a, const pair &b) {
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    })> g;
    // {무게, 가격}, 가격이 높은 순서대로 정렬됨, 가격이 같으면 무게가 큰 순서대로 정렬
    for(int i=0; i<k; i++) {
        int bag = bags[i];
        while(!gems.empty()) {
            if(gems.top().first > bag) break;
            g.push(gems.top());
            gems.pop();
        }
        if(g.empty()) continue;
        value += g.top().second; g.pop();
    }
    std::cout << value << '\n';
    return 0;
}