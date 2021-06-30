#include <iostream>
#include <string>
#include <vector>

#define FASTIO

int GCD(int a, int b) {
    if(b == 0) return a;
    if(b == 1) return 1;
    return GCD(b, a%b);
}

std::vector<int> get_failure_func(std::string pattern) {
    int plen = pattern.size();
    std::vector<int> ret(plen, 0);
    int j=0;
    for(int i=1; i<plen; i++) {
        while(j > 0 && pattern[i] != pattern[j]) j = ret[j-1];
        if(pattern[i] == pattern[j]) ret[i] = ++j;
    }
    return ret;
}

int main() {
    #ifdef FASTIO
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    #endif
    int n;
    std::cin >> n;
    std::string text = "", pattern = "";
    for(int i=0; i<n; i++) {
        char c;
        std::cin >> c;
        pattern += c;
    }
    for(int i=0; i<n; i++) {
        char c;
        std::cin >> c;
        text += c;
    }
    text += text;
    text.pop_back();
    auto prep = get_failure_func(pattern);
    int j = 0, cnt = 0, tlen = text.size();
    for(int i=0; i<tlen; i++) {
        while(j > 0 && text[i] != pattern[j]) j = prep[j-1];
        if(text[i] == pattern[j]) {
            if(++j >= n) {
                cnt++;
                j = prep[j-1];
            }
        }
    }
    int gcd = GCD(n, cnt);
    std::cout << cnt/gcd << '/' << n/gcd << '\n';
    return 0;
}