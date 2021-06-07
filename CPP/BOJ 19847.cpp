#include <iostream>
#include <vector>
#include <iomanip>

#define FASTIO
// #define DEBUG

typedef long double uld;
uld cur[1000001];

int main () {
#ifdef FASTIO
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
#endif
    int n;
    std::cin >> n;
    int max_num = INT32_MAX;
    for(int i=0; i<n; i++) {
        int x;
        std::cin >> x;
        if(max_num <= x) continue;
        if(i==0) {
            for(int j=0; j<x; j++) {
                cur[j] = (uld)1.0/x;
            }
        } else {
            for(int j=x; j<max_num; j++) {
                cur[j%x] += cur[j];
                cur[j] = 0;
            }
        }
        max_num = std::min(max_num, x);
#ifdef DEBUG
        for(int j=0; j<max_num; j++) {
            std::cout << cur[j] << ' ';
        }
        std::cout << '\n';
#endif
    }
    uld ev = 0;
    for(int i=0; i<max_num; i++) {
        ev += i*cur[i];
    }
    std::cout << std::setprecision(10) << ev << '\n';
}