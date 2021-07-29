#include <iostream>
#include <vector>

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
    if(red_tiles.size() == 1) {
        std::cout << red_tiles[0] << '\n';
    } else {
        int ans = -1;
        for(int i=0; i<red_tiles.size()-1; i++) {
            ans = std::max(ans, red_tiles[i] + red_tiles[i+1]);
        }
        std::cout << ans << '\n';
    }
}