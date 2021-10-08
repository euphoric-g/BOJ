#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iterator>

int main() {
    int n;
    fscanf(stdin, "%d", &n);
    std::vector<std::pair<int, int>> towers; // index, height
    std::vector<int> ret;
    for(int i=1; i<=n; i++) {
        int h;
        fscanf(stdin, "%d", &h);
        while(!towers.empty()) {
            if(towers.back().second > h) {
                printf("%d ", towers.back().first);
                break;
            } else {
                towers.pop_back();
            }
        }
        if(towers.empty()) printf("0 ");
        towers.push_back(std::pair<int, int>(i, h));
    }
    printf("\n");
    return 0;
    /*
    std::vector<int> ret;
    std::queue<std::pair<int, int>> q;
    for(int i=1; i<=n; i++) {
        int h;
        fscanf(stdin, "%d", &h);
        towers.push_back(std::pair<int, int>(i, h));
        ret.push_back(0);
    }
    // first -> index, second -> height
    while(!towers.empty()) {
        std::pair<int, int> get = towers.back(); towers.pop_back();
        int qsz = q.size();
        while(qsz-->0) {
            std::pair<int, int> qd = q.front(); q.pop();
            // get = 신호를 받은 탑
            // qd = 신호를 보낸 탑
            if(qd.second < get.second) {
                // 받을 수 있으면 ret에 저장
                ret[qd.first-1] = get.first;
            } else {
                // 받을 수 없으면 queue 뒤로 보냄
                q.push(qd);
            }
        }
        q.push(get);
    }
    for(const auto &data : ret) {
        printf("%d ", data);
    }
    printf("\n");
    */
}