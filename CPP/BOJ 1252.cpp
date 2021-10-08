#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<bool> add(std::vector<bool> a, std::vector<bool> b) {
    std::vector<bool> ret;
    int cur = 0;
    int alen = a.size();
    int blen = b.size();
    bool carry = false;
    while(cur < alen || cur < blen || carry) {
        bool acur = cur < alen ? a[cur] : false;
        bool bcur = cur < blen ? b[cur] : false;
        ret.push_back(acur ^ bcur ^ carry);
        carry = (acur && bcur) || (bcur && carry) || (acur && carry);
        cur++;
    }
    return ret;
}

int main() {
    std::string bin1, bin2;
    std::cin >> bin1 >> bin2;
    std::vector<bool> b1, b2;
    for(auto it = bin1.rbegin(); it != bin1.rend(); it++) {
        b1.push_back((*it == '1' ? true : false));
    }
    for(auto it = bin2.rbegin(); it != bin2.rend(); it++) {
        b2.push_back((*it == '1' ? true : false));
    }
    std::vector<bool> ans = add(b1, b2);
    while(ans.back() == false && ans.size() > 1) {
        ans.pop_back();
    }
    while(!ans.empty()) {
        std::cout << (ans.back() ? "1" : "0");
        ans.pop_back();
    }
    std::cout << std::endl;
}