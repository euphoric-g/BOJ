#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

long double func(std::vector<int> nums) {
    long double sum = 0;
    for(const auto& n : nums) sum += n;
    long double avg = sum / nums.size();
    long double var = 0;
    for(const auto& n : nums) var += (n - avg)*(n - avg);
    var /= nums.size();
    long double sdev = sqrt(var);
    return sdev;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> list;
    for(int i=0; i<n; i++) {
        int input;
        std::cin >> input;
        list.push_back(input);
    }
    long double min_sdev = -1;
    for(int i=0; i<=n-k; i++) {
        for(int j=i+k; j<=n; j++) {
            std::vector<int> temp;
            temp.assign(list.begin() + i, list.begin() + j);
            long double sdev = func(temp);
            min_sdev = min_sdev == -1 ? sdev : std::min(sdev, min_sdev);
        }
    }
    std::cout << std::setprecision(12) << min_sdev << std::endl;
}