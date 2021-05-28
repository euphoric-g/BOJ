#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
    std::string str;
    std::cin >> str;
    std::vector<std::string> arr;
    for(int i=0; i<str.size(); i++) {
        arr.push_back(str.substr(i, str.size()));
    }
    std::sort(arr.begin(), arr.end());
    for(const auto &suffix : arr) std::cout << suffix << '\n';
    return 0;
}