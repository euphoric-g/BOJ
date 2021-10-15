#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef struct _customer {
    int id, time;
} customer;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m, t, w, elapsed = 0;
    std::cin >> n >> t >> w;
    std::queue<customer> bank_queue;
    for(int i=0; i<n; i++) {
        int px, tx;
        std::cin >> px >> tx;
        bank_queue.push(customer{px, tx});
    }
    std::cin >> m;
    std::queue<std::pair<int, customer>> new_customers;
    std::vector<std::pair<int, customer>> temp;
    for(int i=0; i<m; i++) {
        int px, tx, cx;
        std::cin >> px >> tx >> cx;
        temp.push_back({cx, customer{px, tx}});
    }
    std::sort(temp.begin(), temp.end(), [](const std::pair<int, customer> &a, const std::pair<int, customer> &b) -> bool {
        return a.first < b.first;
    });
    for(const auto &pair : temp) new_customers.push(pair);
    while(elapsed < w) {
        auto front = bank_queue.front(); bank_queue.pop();
        if(front.time >= t) {
            int repeat = t;
            while(repeat > 0 && elapsed < w) {
                elapsed++, repeat--, front.time--;
                std::cout << front.id << '\n';
            }
        } else {
            int repeat = front.time;
            while(repeat > 0 && elapsed < w) {
                elapsed++, repeat--, front.time--;
                std::cout << front.id << '\n';
            }
        }
        while(!new_customers.empty() && new_customers.front().first <= elapsed) {
            bank_queue.push(new_customers.front().second);
            new_customers.pop();
        }
        if(front.time > 0) bank_queue.push(front);
    }
    return 0;
}