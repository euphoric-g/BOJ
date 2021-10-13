#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int t = 1;
    int n, waste;
    while(std::cin >> n) {
        if(n == 0) break;
        while(n--) std::cin >> waste;
        std::cout << "Case " << t++ << ": Sorting... done!\n";
    }
}