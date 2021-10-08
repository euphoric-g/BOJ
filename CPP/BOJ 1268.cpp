#include <iostream>
#include <vector>

typedef std::vector<int> vint;

int main() {
    int n;
    std::cin >> n;
    vint arr[6][10];
    int data[1001][6];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=5; j++) {
            std::cin >> data[i][j];
            arr[j][data[i][j]].push_back(i);
        }
    }
    int max_cnts = 0;
    int cnts[1001] = {0, };
    for(int i=1; i<=n; i++) {
        int check[1001] = {0, };
        for(int j=1; j<=5; j++) {
            // i번 학생의 j학년 확인
            for(const auto &d : arr[j][data[i][j]]) {
                ++check[d];
            }
        }
        for(int j=1; j<=n; j++) {
            if(check[j] > 0 && i!=j) cnts[i]++;
        }
        max_cnts = std::max(max_cnts, cnts[i]);
    }
    for(int i=1; i<=n; i++) {
        if(cnts[i] == max_cnts) {
            std::cout << i << std::endl;
            return 0;
        }
    }
}