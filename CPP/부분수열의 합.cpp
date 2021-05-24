#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, s, cnt = 0;
    std::cin >> n >> s;
    std::vector<int> arr(n, 0);
    for(int i=0; i<n; i++) std::cin >> arr[i];
    for(int i=1; i<(1 << n); i++) {
        int mask = i;
        int sum = 0;
        for(int j=0; j<n; j++) {
            if((mask >> j) % 2 == 1) {
                sum += arr[j];
            }
        }
        if(sum == s) cnt++;
    }
    std::cout << cnt << '\n';
    return 0;
}