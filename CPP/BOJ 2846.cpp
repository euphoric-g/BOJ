#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int max_height = 0, start = 0, start_height = 0, last = 0;
    for(int i=0; i<n; i++) {
        int pi;
        std::cin >> pi;
        if(i==0) {
            start_height = pi;
        } else {
            if(pi > last) {
                max_height = std::max(max_height, pi - start_height);
            } else {
                start = i;
                start_height = pi;
            }
        }
        last = pi;
    }
    std::cout << max_height << '\n';
}