#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

int arr[201][201];
int r, c;

bool compare(const std::pair<int, int>&a, const std::pair<int, int>&b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void OP_R() {
    int stored_c = c;
    int max_c = c;
    std::vector<int> rend;
    for(int i=0; i<r; i++) {
        std::map<int, int> m;
        for(int j=0; j<stored_c; j++) m[arr[i][j]]++;
        std::vector<std::pair<int, int>> vec;
        for(const auto &item : m) vec.push_back({item.first, item.second});
        std::sort(vec.begin(), vec.end(), compare);
        c = 0;
        for(const auto &item : vec) {
            if(item.first == 0) continue;
            arr[i][c++] = item.first;
            arr[i][c++] = item.second;
        }
        if(c > 100) c = 100;
        rend.push_back(c);
        max_c = std::max(max_c, c);
    }
    for(int i=0; i<r; i++) {
        for(int j=rend[i]; j<max_c; j++) {
            arr[i][j] = 0;
        }
    }
    c = max_c;
}

void OP_C() {
    int stored_r = r;
    int max_r = r;
    std::vector<int> cend;
    for(int i=0; i<c; i++) {
        std::map<int, int> m;
        for(int j=0; j<stored_r; j++) m[arr[j][i]]++;
        std::vector<std::pair<int, int>> vec;
        for(const auto &item : m) vec.push_back({item.first, item.second});
        std::sort(vec.begin(), vec.end(), compare);
        r = 0;
        for(const auto &item : vec) {
            if(item.first == 0) continue;
            arr[r++][i] = item.first;
            arr[r++][i] = item.second;
        }
        if(r > 100) r = 100;
        cend.push_back(r);
        max_r = std::max(max_r, r);
    }
    for(int i=0; i<c; i++) {
        for(int j=cend[i]; j<max_r; j++) {
            arr[j][i] = 0;
        }
    }
    r = max_r;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int rt, ct, k;
    std::cin >> rt >> ct >> k;
    r = 3, c = 3;
    int time = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            std::cin >> arr[i][j];
        }
    }
    auto show = [](){
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    };
    while(time <= 100 && arr[rt-1][ct-1] != k) {
        time++;
        if(r >= c) {
            OP_R();
        } else {
            OP_C();
        }
        // show();
    }
    std::cout << (time > 100 ? -1 : time) << '\n';
    return 0;
}