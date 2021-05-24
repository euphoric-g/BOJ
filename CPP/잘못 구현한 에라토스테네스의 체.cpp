#include <iostream>
#include <cmath>

typedef long long ll;
int main() {
    int n;
    std::cin >> n;
    n--;
    ll sum = 0;
    for(int i=n+1; i != 0; i = n/(n/i+1)) {
        // 최대 거리 1 -> n+1 = n (1, 2, ..., n-1, n, n+1)
        // 1부터 n+1까지 i 갯수 = 1, i+1, 2*i+1, 3*i+1, ...
        // k*i+1 <= n+1, k <= n/i
        // 0부터 n/i 까지 (n/i)+1개 들어간다.
        // ex) n = 11, i = 5일때, k=2이므로 0, 1, 2 -> 3개

        // 다음 i값은 k 값이 바뀌는 i,
        // next_i = n/(n/i+1)
        // current_i = i
        // i 값의 간격 = i-(n/(n/i+1))
        sum += (n/i+1) * (i-(n/(n/i+1)));
    }
    std::cout << sum << std::endl;
}