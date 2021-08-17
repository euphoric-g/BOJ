#include <iostream>
#include <iomanip>
#include <string>

// #define DEBUG

typedef unsigned long long ull;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    while(n--) {
        // 입력
        std::string a, b;
        std::cin >> a >> b;

        // 부호 처리
        int sign = 1;
        if(a[0] == '-') sign *= -1;
        if(b[0] == '-') sign *= -1;
        std::string str_sign = sign == -1 ? "-" : "";

        // 소수점 제거
        auto it = a.find('.', 0);
        a = a.substr(0, it) + a.substr(it+1, a.size());
        it = b.find('.', 0);
        b = b.substr(0, it) + b.substr(it+1, b.size());

        // 부호 제거
        if(a[0] == '-') a = a.substr(1, a.size());
        if(b[0] == '-') b = b.substr(1, b.size());

        // 중간 확인
        #ifdef DEBUG
        std::cout << a << '\n' << b << '\n';
        #endif

        ull ull_a = std::stoull(a), ull_b = std::stoull(b);
        ull mul = ull_a * ull_b;

        #ifdef DEBUG
        std::cout << mul << '\n';
        #endif

        std::string str_mul = std::to_string(mul);
        std::string ans;

        if(str_mul.size() > 18) {
            ans = str_sign + str_mul.substr(0, str_mul.size()-18) + "." + str_mul.substr(str_mul.size()-18, str_mul.size());
        } else {
            ans = str_sign + "0." + std::string(18 - str_mul.size(), '0') + str_mul;
        }

        std::cout << ans << '\n';
    }
}