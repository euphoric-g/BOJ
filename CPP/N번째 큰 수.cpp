#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i=0; i<n; i++) {
        int in;
        scanf("%d", &in);
        pq.push(in);
    }
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n; j++) {
            int in;
            scanf("%d", &in);
            pq.push(in);
            pq.pop();
        }
    }
    printf("%d\n", pq.top());
    return 0;
}