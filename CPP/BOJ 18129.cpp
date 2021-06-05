#include <iostream>
#include <string>

int main() {
    std::string str, ret = "";
    int k;
    std::cin >> str >> k;
    int cur = 0;
    bool check[26] = {false, };
    for(auto &ch : str) ch = tolower(ch);
    char last = str[0];
    for(auto &ch : str) {
        if(ch == last) cur++;
        else if(cur >= k) {
            if(!check[last - 'a']) {
                check[last - 'a'] = true;
                ret += "1";
            }
            cur = 1;
        } else {
            if(!check[last - 'a']) {
                check[last - 'a'] = true;
                ret += "0";
            }
            cur = 1;
        }
        last = ch;
    }
    if(!check[last - 'a']) {
        if(cur >= k) ret += "1";
        else ret += "0";
    }

    std::cout << ret << '\n';
    return 0;
}