#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int k, c;
    std::cin >> k >> c;
    while(c--) {
        int m, n;
        std::cin >> m >> n;
        if(m > n) {
            bool flag = true;
            int curm = n, curn = n;
            int chances = k - n;
            while(curm < m) {
                curm++;
                int diff = curm - curn;
                if(--chances < diff && curm != m) {
                    flag = false;
                    break;
                }
            }
            if(flag) std::cout << "1\n";
            else std::cout << "0\n";
        } else if(m < n) {
            bool flag = true;
            int curm = m, curn = m;
            int chances = k - m;
            while(curn < n) {
                int diff = curn - curm;
                if(--chances < diff) {
                    flag = false;
                    break;
                }
                curn++;
            }
            if(flag) std::cout << "1\n";
            else std::cout << "0\n";
        } else {
            std::cout << "1\n";
        }
    }
}

/*
K=3, M=1, N=3
OO
XO
X(끝) 불가능

K=3, M=2, N=0
OX
OX(끝) 가능

K=3, M=3, N=0
OX
OX(끝) 불가능

*/