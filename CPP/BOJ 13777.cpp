#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    while(1) {
        int ans;
        std::cin >> ans;
        if(ans == 0) break;
        std::vector<int> find_list;
        int left = 1, right = 50, mid;
        while(1) {
            mid = (left + right)/2;
            find_list.push_back(mid);
            if(mid == ans) break;
            if(mid > ans) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        for(const auto &item : find_list) std::cout << item << ' ';
        std::cout << '\n';
    }
    return 0;
}