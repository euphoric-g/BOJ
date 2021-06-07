#include <iostream>
#include <map>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::cin.ignore();
    for(int i=1; i<=n; i++) {
        std::string str;
        std::map<char, int> dict;
        std::getline(std::cin, str);
        for(const auto &ch : str) {
            if(isalpha(ch)) {
                dict[tolower(ch)]++;
            }
        }
        int max = INT32_MAX;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            max = std::min(max, dict[ch]);
        }
        std::cout << "Case " << i << ": ";
        if(max >= 3) {
            std::cout << "Triple pangram!!!\n";
        } else if(max == 2) {
            std::cout << "Double pangram!!\n";
        } else if(max == 1) {
            std::cout << "Pangram!\n";
        } else if(max <= 0) {
            std::cout << "Not a pangram\n";
        }
    }
}