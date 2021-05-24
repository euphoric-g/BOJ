#include <cstdio>
#include <algorithm>
#include <queue>

int main() {
    int n;
    fscanf(stdin, "%d", &n);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i=0; i<n; i++) {
        int in;
        fscanf(stdin, "%d", &in);
        if(in == 0) {
            if(pq.empty()) printf("0\n");
            else {
                printf("%d\n", pq.top());
                pq.pop();
            }
        } else {
            pq.push(in);
        }
    }
}