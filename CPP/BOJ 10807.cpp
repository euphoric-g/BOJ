#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> um;
    while(n--) {
        int num;
        std::cin >> num;
        um[num]++;
    }
    int v;
    std::cin >> v;
    std::cout << um[v] << '\n';
}