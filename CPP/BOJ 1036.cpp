#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define DEBUG

#define ALPHABET 36
#define MAX_LENGTH 53

int main() {
    auto char_to_int = [](const char &c) -> int {
        if(c >= '0' && c <= '9') return c - '0';
        return c - 'A' + 10;
    };
    auto int_to_char = [](const int &n) -> char {
        if(n < 10) return '0' + n;
        return 'A'+(n-10);
    };
    int sum[MAX_LENGTH] = {0, };
    int benefit[ALPHABET][MAX_LENGTH];
    for(int i=0; i<ALPHABET; i++) {
        for(int j=0; j<MAX_LENGTH; j++) {
            benefit[i][j] = 0;
        }
    }
    int n, k;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        std::string num_str;
        std::cin >> num_str;
        for(int j=0; j<num_str.size(); j++) {
            sum[MAX_LENGTH-j-1] += 35 - char_to_int(num_str[j]);
            benefit[char_to_int(num_str[j])][MAX_LENGTH-j-1] += 35 - char_to_int(num_str[j]);
        }
    }
    std::cin >> k;
    for(int i=MAX_LENGTH-1; i>0; i--) {
        if(sum[i] >= 36) {
            sum[i] += sum[i] / 36;
            sum[i] %= 36;
        }
    }
    for(int i=0; i<ALPHABET; i++) {
        for(int j=MAX_LENGTH-1; j>0; j--) {
            while(benefit[i][j] >= 36) {
                benefit[i][j] -= 36;
                benefit[i][j-1]++;
            }
        }
    }
    #ifdef DEBUG
    for(int i=0; i<ALPHABET; i++) {
        for(int j=0; j<MAX_LENGTH; j++) {
            std::cout << int_to_char(benefit[i][j]);
        }
        std::cout << '\n';
    }
    #endif
    std::vector<std::pair<char, std::string>> arr;
    for(int i=0; i<ALPHABET; i++) {
        std::string base36 = "";
        int j = 0;
        while(benefit[i][j] == 0 && j < MAX_LENGTH) j++;
        for(; j < MAX_LENGTH; j++) base36 += int_to_char(benefit[i][j]);
        if(!base36.empty()) arr.push_back({int_to_char(i), base36});
    }
    std::sort(arr.begin(), arr.end(), [](const std::pair<char, std::string> &a, const std::pair<char, std::string> &b) -> bool {
        if(a.second.size() != b.second.size()) return a.second.size() > b.second.size();
        return a.second > b.second;
    });
    #ifdef DEBUG
    for(int i=0; i<arr.size(); i++) {
        std::cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    #endif
    for(int i=0; i<arr.size(); i++) {
        if(i < k) {
            for(int j=0; j<arr[i].second.size(); j++) {
                sum[MAX_LENGTH-j-1] += 35 - char_to_int(arr[i].second[j]);
            }
        }
    }
    for(int i=MAX_LENGTH-1; i>0; i--) {
        if(sum[i] >= 36) {
            sum[i-1] += sum[i] / 36;
            sum[i] %= 36;
        }
    }
    std::string sum_base36 = "";
    int i = 0;
    while(sum[i] == 0 && i < MAX_LENGTH) i++;
    for(; i<MAX_LENGTH; i++) {
        sum_base36 += int_to_char(sum[i]);
    }
    std::cout << sum_base36 << '\n';
    return 0;
}