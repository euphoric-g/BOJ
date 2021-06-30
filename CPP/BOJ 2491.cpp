#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int max_increase = 1;
    int max_decrease = 1;
    int cur_in = 1, cur_de = 1;
    int last;
    for(int i=0; i<n; i++) {
        int input;
        std::cin >> input;
        if(i == 0) {
            last = input;
            cur_in = 1, cur_de = 1;
            continue;
        }
        if(input > last) {
            cur_in++;
            cur_de = 1;
        } else if(input < last) {
            cur_de++;
            cur_in = 1;
        } else {
            cur_de++, cur_in++;
        }
        max_increase = std::max(max_increase, cur_in);
        max_decrease = std::max(max_decrease, cur_de);
        last = input;
    }
    std::cout << std::max(max_increase, max_decrease) << '\n';
    return 0;
}