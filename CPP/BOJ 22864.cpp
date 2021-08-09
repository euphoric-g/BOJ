#include <iostream>

int main() {
    int a, b, c, m;
    std::cin >> a >> b >> c >> m;
    int fatigue = 0, time = 0, work = 0;
    while(time < 24) {
        if(fatigue + a <= m) {
            work += b;
            fatigue += a;
        } else {
            fatigue -= c;
            if(fatigue < 0) fatigue = 0;
        }
        time++;
    }
    std::cout << work << '\n';
}