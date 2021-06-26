#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// #define DEBUG

#define ALPHABET 36
#define MAX_LENGTH 53

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
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
        int numlen = num_str.size();
        for(int j=0; j<numlen; j++) {
            sum[MAX_LENGTH-numlen+j] += char_to_int(num_str[j]);
            benefit[char_to_int(num_str[j])][MAX_LENGTH-numlen+j] += 35 - char_to_int(num_str[j]);
        }
    }
    std::cin >> k;
    for(int i=MAX_LENGTH-1; i>0; i--) {
        if(sum[i] >= 36) {
            sum[i-1] += sum[i] / 36;
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
    std::cout << "SUM = \t";
    for(int i=0; i<MAX_LENGTH; i++) {
        std::cout << int_to_char(sum[i]);
    }
    std::cout << '\n';
    for(int i=0; i<ALPHABET; i++) {
        std::cout << int_to_char(i) << '\t';
        for(int j=0; j<MAX_LENGTH; j++) {
            std::cout << int_to_char(benefit[i][j]);
        }
        std::cout << '\n';
    }
    #endif
    std::vector<std::pair<char, std::string>> arr;
    for(int i=0; i<ALPHABET; i++) {
        std::string base36 = "";
        for(int j=0; j < MAX_LENGTH; j++) base36 += int_to_char(benefit[i][j]);
        arr.push_back({int_to_char(i), base36});
    }
    std::sort(arr.begin(), arr.end(), [](const std::pair<char, std::string> &a, const std::pair<char, std::string> &b) -> bool {
        if(a.second.size() != b.second.size()) return a.second.size() > b.second.size();
        return a.second > b.second;
    });
    #ifdef DEBUG
    std::cout << "Sort complete\n";
    for(int i=0; i<arr.size(); i++) {
        std::cout << arr[i].first << '\t' << arr[i].second << '\n';
    }
    #endif
    for(int i=0; i<arr.size(); i++) {
        if(i < k) {
            #ifdef DEBUG
            std::cout << "Select " << arr[i].first << '\n';
            #endif
            for(int j=0; j<MAX_LENGTH; j++) {
                sum[j] += char_to_int(arr[i].second[j]);
            }
            for(int j=MAX_LENGTH-1; j>0; j--) {
                if(sum[j] >= 36) {
                    sum[j-1] += sum[j] / 36;
                    sum[j] %= 36;
                }
            }
            #ifdef DEBUG
            std::cout << "after add " << arr[i].first << ", sum = ";
            for(int i=0; i<MAX_LENGTH; i++) {
                std::cout << int_to_char(sum[i]);
            }
            std::cout << '\n';
            #endif
        }
    }
    for(int i=MAX_LENGTH-1; i>0; i--) {
        if(sum[i] >= 36) {
            sum[i-1] += sum[i] / 36;
            sum[i] %= 36;
        }
    }
    std::string sum_base36 = "";
    for(int i=0; i<MAX_LENGTH; i++) {
        sum_base36 += int_to_char(sum[i]);
    }
    std::reverse(sum_base36.begin(), sum_base36.end());
    while(sum_base36.back() == '0') sum_base36.pop_back();
    std::reverse(sum_base36.begin(), sum_base36.end());
    std::cout << (sum_base36 == "" ? "0" : sum_base36) << '\n';
    return 0;
}