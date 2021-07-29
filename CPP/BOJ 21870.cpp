#include <iostream>
#include <algorithm>
#include <vector>

int n;
int max_beauty = -1;
std::vector<int> arr;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void recursive(int left, int right, int gcd_sum) {
    // std::cout << left << ' ' << right << ' ' << gcd_sum << '\n';
    if(right - left == 1) {
        max_beauty = std::max(max_beauty, gcd_sum + arr[left]);
        return;
    }
    int sep = left + (right - left)/2;
    // (left, sep) + (sep, right)
    int gcd_left = arr[left], gcd_right = arr[sep];
    int cur = left;
    while(cur < sep) {
        gcd_left = gcd(gcd_left, arr[cur]);
        cur++;
    }
    while(cur < right) {
        gcd_right = gcd(gcd_right, arr[cur]);
        cur++;
    }
    recursive(left, sep, gcd_sum + gcd_right);
    recursive(sep, right, gcd_sum + gcd_left);
}

int main() {
    std::cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) std::cin >> arr[i];
    recursive(0, n, 0);
    std::cout << max_beauty << '\n';
}