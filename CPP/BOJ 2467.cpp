#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for(int i=0; i<n; ++i) {
        std::cin >> vec[i];
    }
    int l = 0, r = n-1;
    int max_sum = INT32_MAX;
    std::pair<int, int> pair;
    while(l < r) {
        int sum = vec[l] + vec[r];
        if(abs(sum) < max_sum) {
            max_sum = abs(sum);
            pair = {vec[l], vec[r]};
        }
        if(sum > 0) {
            r--;
        } else if(sum < 0) {
            l++;
        } else break;
    }
    std::cout << pair.first << ' ' << pair.second << '\n';
    return 0;
}