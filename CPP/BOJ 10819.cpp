#include <iostream>
#include <vector>

int n;
bool selected[8];
int max_val = -1;

void backtracking(std::vector<int> &arr, std::vector<int> &bt, int depth) {
    if(depth == n) {
        int ans = 0;
        for(int i=0; i<n-1; i++) {
            ans += abs(bt[i] - bt[i+1]);
        }
        max_val = std::max(max_val, ans);
        return;
    }
    for(int i=0; i<n; i++) {
        if(!selected[i]) {
            bt.push_back(arr[i]);
            selected[i] = true;
            backtracking(arr, bt, depth+1);
            selected[i] = false;
            bt.pop_back();
        }
    }
}

int main() {
    std::cin >> n;
    std::vector<int> arr(n, 0);
    std::vector<int> bt;
    for(int i=0; i<n; i++) std::cin >> arr[i];
    backtracking(arr, bt, 0);
    std::cout << max_val << '\n';
    return 0;
}