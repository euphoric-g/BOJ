#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cards(n);
    std::vector<int> rule(n);
    for(int i=0; i<n; i++) std::cin >> cards[i];
    for(int i=0; i<n; i++) {
        std::cin >> rule[i];
        --rule[i];
    }
    while(k--) {
        std::vector<int> copy = cards;
        for(int i=0; i<n; i++) {
            copy[rule[i]] = cards[i];
        }
        cards = copy;
    }
    for(const auto &card : cards) std::cout << card << ' ';
    std::cout << '\n';
}