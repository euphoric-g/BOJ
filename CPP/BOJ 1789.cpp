#include <iostream>
#include <cmath>

int main() {
    // 1~(int)sqrt(200)=14 합계 = 15*16/2 = 120
    // 4 추가 해야함
    // 
    long long s;
    std::cin >> s;
    long long n = sqrt(s);
    while(((n+2)*(n+1))/2 <= s) n++;
    std::cout << n << '\n';
    return 0;
}