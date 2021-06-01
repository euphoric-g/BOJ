#include <iostream>
#include <algorithm>

#define ARR_SIZE 8

int main() {
    std::pair<int, int> arr[ARR_SIZE];
    for(int i=0; i<ARR_SIZE; i++) {
        int score;
        std::cin >> score;
        arr[i] = {score, i+1};
    }
    std::sort(arr, arr + ARR_SIZE, [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
        return a.first > b.first;
    });
    int qnum[5];
    for(int i=0; i<5; i++) qnum[i] = arr[i].second;
    std::sort(qnum, qnum+5, std::less<int>());
    int sum = 0;
    for(int i=0; i<5; i++) sum += arr[i].first;
    std::cout << sum << '\n';
    for(int i=0; i<5; i++) std::cout << qnum[i] << ' ';
    std::cout << '\n';
    return 0;
}