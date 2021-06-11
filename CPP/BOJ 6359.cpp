#include <iostream>

#define CLOSE 0
#define OPEN 1

int main() {
    int t;
    std::cin >> t;
    auto toggle = [](int &v) {
        if(v == OPEN) v = CLOSE;
        else if(v == CLOSE) v = OPEN;
    };
    while(t--) {
        int n;
        std::cin >> n;
        int arr[n+1] = { CLOSE, };
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j+=i) {
                toggle(arr[j]);
            }
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) if(arr[i] == OPEN) cnt++;
        std::cout << cnt << '\n';
    }
    return 0;
}