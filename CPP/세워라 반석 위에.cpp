#include <iostream>
#include <vector>

std::vector<int> dp[8];

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        int get;
        std::cin >> get;
        for(int j=0; j<8; j++) {
            if(!(j+1 <= get && get <= j+3)) dp[j].push_back(i);
        }
    }
    for(int i=0; i<8; i++) dp[i].push_back(n);
    int maxlen = 1;
    for(int i=0; i<8; i++) {
        int temp_max = 0;
        int last = -1;
        for(const int &num : dp[i]) {
            temp_max = std::max(temp_max, num-last-1);
            last = num;
        }
        maxlen = std::max(maxlen, temp_max);
    }
    std::cout << maxlen << '\n';
}