#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> num(5);
    for(int i=0; i<5; i++) {
        std::cin >> num[i];
    }
    std::sort(num.begin(), num.end());
    std::cout << (num[0] + num[1] + num[2] + num[3] + num[4])/5 << '\n' << num[2] << '\n';
}