#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

typedef std::pair<std::string, std::string> timeset;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    auto compare_string = [](const std::string &s1, const std::string &s2) -> bool { return s1 > s2; };
    auto compare_timeset = [](const timeset &ts1, const timeset &ts2) -> bool {
        if(ts1.first != ts2.first) return ts1.first < ts2.first;
        return ts1.second < ts2.second;
    };
    std::vector<timeset> vec_ts;
    for(int i=0; i<n; i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        vec_ts.push_back(timeset(s1, s2));
    }
    std::sort(vec_ts.begin(), vec_ts.end(), compare_timeset);
    std::priority_queue<std::string, std::vector<std::string>, decltype(compare_string)> pq;
    pq.push("0");
    for(const auto &ts : vec_ts) {
        auto get = pq.top(); pq.pop();
        if(ts.first < get) {
            pq.push(get);
            pq.push(ts.second);
        } else {
            pq.push(ts.second);
        }
    }
    std::cout << pq.size() << '\n';
}