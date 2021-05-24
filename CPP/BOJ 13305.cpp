#include <iostream>

#define LENGTH 0
#define PRICE 1

typedef unsigned long long ll;

int main() {
    ll n;
    std::cin >> n;
    ll arr[100001][2];
    for(int i=0; i<n-1; i++) {
        std::cin >> arr[i][LENGTH];
    }
    for(int i=0; i<n; i++) {
        std::cin >> arr[i][PRICE];
    }
    ll cur = 0;
    ll cheap = INT64_MAX, sum = 0;
    while(cur != n-1) {
        cheap = std::min(cheap, arr[cur][PRICE]);
        sum += arr[cur][LENGTH] * cheap;
        cur++;
    }
    std::cout << sum << '\n';
    return 0;
}