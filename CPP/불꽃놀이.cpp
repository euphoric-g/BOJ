#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    int temp, left, right;
    for(int i=0; i<n; i++) {
        std::cin >> temp;
        if(i==0) left = temp;
        if(i==n-1) right = temp;
    }
    left--; right--;
    int cnt = n-3;
    while(cnt > 0) {
        if(left > right && left-right <= cnt) {
            cnt -= (left - right);
            left -= (left - right);
        } else if(left > right && left-right > cnt) {
            left -= cnt;
            cnt = 0;
        } else if(left < right && right-left <= cnt) {
            cnt -= right - left;
            right -= right - left;
        } else if(left < right && right - left > cnt) {
            right -= cnt;
            cnt = 0;
        } else {
            if(cnt % 2 == 0) {
                left -= cnt/2;
                right -= cnt/2;
                cnt = 0;
            } else {
                left -= cnt/2 + 1;
                right -= cnt/2;
                cnt = 0;
            }
        }
    }
    std::cout << std::max(left, right) << "\n";
    return 0;
}