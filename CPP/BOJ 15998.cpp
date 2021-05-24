#include <iostream>

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
    ll gcd = -1, max_val = 0;
    ll last = 0;
    for(int i=0; i<n; i++) {
        ll a, b;
        std::cin >> a >> b;
        if(a > 0 || last + a == b) {
            last = b;
            continue;
        }
        ll km = b - last - a;
        gcd = gcd == -1 ? km : GCD(gcd, km);
        max_val = std::max(max_val, b);
    }
    if(gcd == -1) {
        std::cout << "1\n";
    } else if(max_val >= gcd) {
        std::cout << "-1\n";
    } else {
        std::cout << gcd << '\n';
    }
    return 0;
    // 잔액 + 차감액 + k * 최소 충전잔위 M = 새로운 잔액
    // k * 최소 충전단위 M = 새로운 잔액 - 이전 잔액 - 차감액
    // ex) kM = 4500 - 1500 + 17000 = 20000;
    // ex) kM = 9900 - 100 + 200 = 10000;
    // 20000, 10000
    // 4500, 9900
    // kM 값의 GCD와 새 잔액값 저장
    // kM 값들의 GCD = 10000의 약수 중 새 잔액값의 최댓값보다 큰 값
    // 10000의 약수 vs 9900 = 10000

    // kM = 0 - 0 + 5 = 5
    // kM = 1 - 0 + 6 = 7
    // kM 5, 7
    // 잔액 0, 1
    // 1의 약수 중 1보다 큰 값은 없음
}