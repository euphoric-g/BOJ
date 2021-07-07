#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> red_tiles;
    int cur_record = 1;
    for(int i=0; i<n-1; i++) {
        int num;
        std::cin >> num;
        if(num > k) {
            red_tiles.push_back(cur_record);
            cur_record = 1;
        } else {
            cur_record++;
        }
    }
    red_tiles.push_back(cur_record);
    for(const auto &item : red_tiles) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
    std::sort(red_tiles.begin(), red_tiles.end(), [](const int &a, const int &b) -> bool {
        return a > b;
    });
    if(red_tiles.size() == 1) {
        std::cout << red_tiles[0] << '\n';
    } else {
        std::cout << red_tiles[0] + red_tiles[1] << '\n';
    }
}