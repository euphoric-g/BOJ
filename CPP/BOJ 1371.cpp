#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

int main() {
    /*
    std::ifstream fin;
    fin.open("input.txt", std::ios::in);
    */
    // auto &is = fin;
    auto &is = std::cin;
    std::map<char, int> dict;
    std::vector<std::pair<char, int>> arr;
    while(!is.eof()) {
        std::string str;
        std::getline(is, str);
        for(const auto &ch : str) {
            dict[ch]++;
        }
    }
    for(const auto &p : dict) {
        if(isalpha(p.first)) arr.push_back(p);
    }
    std::sort(arr.begin(), arr.end(), [](const std::pair<char, int> &a, const std::pair<char, int> &b) -> bool {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    for(const auto &p : arr) {
        if(p.second == arr[0].second) std::cout << p.first;
    }
    std::cout << '\n';
    return 0;
}