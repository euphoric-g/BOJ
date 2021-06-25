#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::vector<ll> arr;
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        ll num;
        std::cin >> num;
        arr.push_back(num);
    }
    std::sort(arr.begin(), arr.end());
    ll sum = 0;
    for(int i=0; i<n; i++) {
        sum += abs(arr[i] - (i+1));
    }
    std::cout << sum << '\n';
}