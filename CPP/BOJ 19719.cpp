#include <iostream>
#include <algorithm>

int pays[1001], gets[1001];

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    for(int i=0; i<n; i++) {
        int count, from, to;
        std::cin >> count >> from >> to;
        if(count < 0) pays[from] += count;
        else gets[to] += count;
    }
    bool cash_gap = false;
    int day = 1;
    while(!cash_gap && day <= m) {
        // std::cout << "Day " << day << "\nAccount = " << s << "\nPaid " << pays[day] << "\nGet " << gets[day] << '\n';
        s += pays[day];
        if(s < 0) cash_gap = true;
        s += gets[day];
        ++day;
    }
    std::cout << (cash_gap ? "YES\n" : "NO\n");
}