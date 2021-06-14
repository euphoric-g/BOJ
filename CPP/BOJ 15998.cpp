#include <iostream>
#include <vector>

typedef long long ll;

ll GCD(ll a, ll b) {
    if(b == 0) return a;
    if(b == 1) return 1;
    return GCD(b, a%b);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    ll acnt = 0;
    std::vector<ll> km_list;
    ll bmax = INT64_MIN;
    while(n--) {
        ll a, b;
        std::cin >> a >> b;
        if(acnt + a >= 0) {
            if(acnt + a != b) {
                std::cout << "-1\n";
                return 0;
            }
            acnt = b;
            continue;
        }
        km_list.push_back(b-a-acnt);
        bmax = std::max(bmax, b);
        acnt = b;
    }
    if(km_list.empty()) {
        std::cout << "1\n";
        return 0;
    }
    ll gcd = km_list[0];
    for(const auto &km : km_list) {
        // std::cout << km << '\n';
        gcd = GCD(gcd, km);
    }
    // std::cout << gcd << ", " << bmax << '\n';
    if(gcd > bmax) {
        std::cout << gcd << '\n';
    } else {
        std::cout << "-1\n";
    }
    return 0;
}

/*

기존 잔액 acnt원 + a + 최소 충전단위 * k = b
최소 충전단위 M * k = b - a - acnt;
충전 및 결제 후 남은 돈 b는 최소 충전단위 M보다 작아야한다.
kM 목록과 M의 범위 저장

*/