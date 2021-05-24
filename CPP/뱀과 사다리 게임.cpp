#include <iostream>
#include <queue>

const int dice[] = {1, 2, 3, 4, 5, 6};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    int arr[101];
    int warp[101];
    for(int i=1; i<=100; i++) {
        arr[i] = 0;
        warp[i] = 0;
    }
    for(int i=0; i<n+m; i++) {
        int a, b;
        std::cin >> a >> b;
        warp[a] = b;
    }
    std::queue<int> q;
    q.push(1);
    int roll = -1;
    while(!q.empty()) {
        int sz = q.size();
        roll++;
        while(sz-->0) {
            int get = q.front(); q.pop();
            if(get == 100) {
                std::cout << roll << '\n';
                return 0;
            }
            for(int i=0; i<6; i++) {
                int next = get + dice[i];
                if(next > 100) continue;
                if(warp[next] != 0) next = warp[next];
                if(arr[next] == 0) {
                    arr[next] = roll+1;
                    q.push(next);
                }
            }
        }
    }
}