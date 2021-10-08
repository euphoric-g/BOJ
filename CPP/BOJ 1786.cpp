#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string text, pattern;
std::vector<int> pos;
int *prep;

int main() {
    std::getline(std::cin, text, '\n');
    std::getline(std::cin , pattern, '\n');
    int tlen = text.size();
    int plen = pattern.size();
    if(tlen < plen) {
        std::cout << "0\n";
        return 0;
    }
    prep = new int[plen];
    for(int i=0; i<plen; i++) prep[i] = 0;
    int j = 0;
    for(int i=1; i<plen; i++) {
        while(j>0 && pattern[i] != pattern[j]) j = prep[j-1];
        if(pattern[i] == pattern[j]) prep[i] = ++j;
    }
    j = 0;
    for(int i=0; i<tlen; i++) {
        while(j > 0 && text[i] != pattern[j]) {
            j = prep[j-1];
        }
        if(text[i] == pattern[j]) {
            if(++j >= plen) {
                pos.push_back(i-plen+2);
                j = prep[j-1];
            }
        }
    }
    std::cout << pos.size() << std::endl;
    for(const auto &num : pos) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    delete prep;
    return 0;
}