#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        std::string num;
        std::cin >> num;
        std::string rev = num;
        std::reverse(rev.begin(), rev.end());
        std::string sum = std::to_string(std::stoi(num) + std::stoi(rev));
        std::string rev_sum = sum;
        std::reverse(rev_sum.begin(), rev_sum.end());
        if(sum == rev_sum) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}