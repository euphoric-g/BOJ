#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    int fk = k%10, f2k = (2*k)%10;
    std::vector<int> vec;
    for(int i=1; i<=n; i++) {
        if(i%10 == fk || i%10 == f2k) continue;
        vec.push_back(i);
    }
    std::cout << vec.size() << '\n';
    for(const auto &item : vec) std::cout << item << '\n';
}