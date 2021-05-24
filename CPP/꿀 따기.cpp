#include <iostream>
#include <vector>

#define LEFT -1
#define RIGHT 1

int get_sum(std::vector<int> &sum, int from, int to) {
    // (from, to] 범위의 합
    if(from < to) {
        return sum[to] - sum[from];
    } else {
        return sum[from-1] - (to > 0 ? sum[to-1] : 0);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    std::vector<int> sum(n, 0);
    for(int i=0; i<n; i++) {
        std::cin >> arr[i];
        sum[i] = (i > 0 ? sum[i-1]+arr[i] : arr[i]);
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(i != k && j != k) {
                    
                }
            }
        }
    }
}