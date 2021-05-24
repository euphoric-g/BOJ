#include <iostream>

int pow2(int n) {
    return 1 << n;
}
int main() {
    int n, r, c;
    std::cin >> n >> r >> c;
    int cnt = 0;
    while(n > 0) {
        // 각 하위 그리드의 가로 세로 길이 : pow2(n-1)
        // 각 하위 그리드의 요소 개수 : pow2(n)
        // 경계 좌표 : (pow2(n-1), pow2(n-1))
        int sublen = pow2(n)/2;
        int subnum = sublen * sublen;
        if(r < sublen) {
            if(c < sublen) {
                // 첫번째 하위 그리드
            } else {
                // 두번째 하위 그리드
                c -= sublen;
                cnt += subnum;
            }
        } else {
            if(c < sublen) {
                // 세번째 하위 그리드
                r -= sublen;
                cnt += 2 * subnum;
            } else {
                // 네번째 하위 그리드
                r -= sublen;
                c -= sublen;
                cnt += 3 * subnum;
            }
        }
        n--;
    }
    std::cout << cnt << std::endl;
}