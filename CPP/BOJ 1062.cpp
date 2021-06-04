#include <iostream>
#include <vector>
#include <string>

#define DEBUG

#ifdef DEBUG
#include <bitset>
#endif

typedef unsigned int UINT;

std::vector<UINT> dict;
std::string selected = "";
int n, k, max_readable = 0;

UINT convert(std::string &str) {
    UINT ret = 0;
    for(const auto &ch : str) ret |= (1 << (ch - 'a'));
#ifdef DEBUG
    std::cout << "Converted " << str << " into " << std::bitset<32>(ret) << '\n';
#endif
    return ret;
}

void backtracking(char last) {
    if(selected.size() == k) {
        int cnt = 0;
        for(const auto &word : dict) cnt = ((word & convert(selected)) == word) ? cnt+1 : cnt;
        max_readable = max_readable < cnt ? cnt : max_readable;
        return;
    }
    for(char c = last + 1; c <= 'z'; c++) {
        if(k-selected.size() > 'z'- c ) break;
        selected += c;
        backtracking(c);
        selected.pop_back();
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin >> n >> k;
    for(int i=0; i<n; i++) {
        std::string word;
        std::cin >> word;
        dict.push_back(convert(word));
    }
    backtracking('a'-1);
    /*
    for(UINT i=0; i<(1 << 26); i++) {
        if(__builtin_popcount(i) != k) continue;
        int cnt = 0;
        for(const auto &word : dict) cnt = ((word & i) == word) ? cnt+1 : cnt;
        max_readable = max_readable < cnt ? cnt : max_readable;
    }
    */
    std::cout << max_readable << '\n';
    return 0;
}