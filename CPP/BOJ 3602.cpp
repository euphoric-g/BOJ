#include <iostream>

int main() {
    int b, w;
    std::cin >> b >> w;
    std::pair<int, int> p = {std::min(b, w), std::max(b, w)};
    int s = 0, s1 = 0, s2 = 1;
    while(p.first >= s1 && p.second >= s2) {
        s++;
        if(s % 2 == 0) {
            // s가 짝수 이면
            s1 = (s*s)/2, s2 = (s*s)/2;
        } else {
            s1 = (s*s)/2, s2 = (s*s)/2+1;
        }
    }
    std::cout << (s == 0 ? "Impossible\n" : std::to_string(s-1) + '\n');
}