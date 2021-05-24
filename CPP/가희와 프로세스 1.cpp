#include <iostream>
#include <vector>
#include <queue>

class Process {
    public:
    int prior;
    int pid;
    int time;
    Process() {}
    Process(int id, int t, int pr) {
        prior = pr;
        pid = id;
        time = t;
    }
};

struct cmp {
    bool operator()(Process a, Process b) {
        if(a.prior != b.prior) return a.prior < b.prior;
        return a.pid > b.pid;
    }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int T, n;
    std::cin >> T >> n;
    std::priority_queue<Process, std::vector<Process>, cmp> pq;
    for(int i=0; i<n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        pq.push(Process(a, b, c));
    }
    while(T-->0) {
        if(pq.empty()) break;
        Process get = pq.top(); pq.pop();
        std::cout << get.pid << '\n';
        if(--get.time > 0) {
            get.prior--;
            pq.push(get);
        }
    }
}