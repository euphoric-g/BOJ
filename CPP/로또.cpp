#include <iostream>
#include <vector>

void print(std::vector<int> &arr, std::vector<int> &selected) {
    for(int i=0; i<6; i++) {
        std::cout << arr[selected[i]];
        if(i != 5) std::cout << ' ';
    }
    std::cout << '\n';
}

void backtracking(std::vector<int> &arr, std::vector<int> &selected, int last_ind, int left) {
    if(left == 0) {
        print(arr, selected);
    } else if (arr.size() - last_ind < left) {
        return;
        /*
            arr.size() = 8
            2번째 수로 5번을 고르고 진입(left = 4)
            3,6 4,7 5,8 6,9가 되므로 어떤 경우에도 완성 불가 : return
            2번째 수로 4번을 고르고 진입했다면 ? 4 5 6 7 8으로 완성 가능
            arr.size() - last_ind = 8 - 5 = 3
            left = 4
        */
    } else {
        for(int ind = last_ind + 1; ind < arr.size(); ind++) {
            selected[6-left] = ind;
            backtracking(arr, selected, ind, left-1);
        }
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    while(1) {
        int k;
        std::cin >> k;
        if(k == 0) break;
        std::vector<int> arr(k, 0);
        std::vector<int> selected(6, 0);
        for(int i=0; i<k; i++) {
            std::cin >> arr[i];
        }
        backtracking(arr, selected, -1, 6);
        std::cout << '\n';
    }
    return 0;
}