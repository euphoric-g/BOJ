#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

typedef long long ll;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::priority_queue<ll, std::vector<ll>, decltype([](const ll &a, const ll &b) -> bool {
        return a > b;
    })> conf_rooms;
    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>,
    decltype([](const std::pair<ll, ll> &a, const std::pair<ll, ll> &b)-> bool {
        return a.first > b.first;
    })> conferences;
    for(int i=0; i<n; i++) {
        ll a, b;
        std::cin >> a >> b;
        conferences.push({a, b});
    }
    conf_rooms.push(0);
    while(!conferences.empty()) {
        auto conf = conferences.top(); conferences.pop();
        auto room = conf_rooms.top(); conf_rooms.pop();
        if(room > conf.first) {
            // 새 conf_room 생성
            conf_rooms.push(room);
            conf_rooms.push(conf.second);
        } else {
            // 해당 room 이용
            conf_rooms.push(conf.second);
        }
    }
    std::cout << conf_rooms.size() << '\n';
    return 0;
}