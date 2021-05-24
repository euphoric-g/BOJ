#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int getPi(std::string &str) {
    int strlen = str.size();
    int j=0;
    int *pi = new int[strlen];
    int max_val = 0;
    for(int i=0; i<strlen; i++) pi[i] = 0;
    for(int i=1; i<strlen; i++) {
        while(j > 0 && str[i] != str[j]) {
            j = pi[j-1];
        }
        if(str[i] == str[j]) {
            pi[i] = ++j;
            max_val = std::max(pi[i], max_val);
        }
    }
    delete pi;
    return max_val;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string str;
    std::cin >> str;
    int strlen = str.size();
    int maximum = 0;
    for(int i=0; i<strlen; i++) {
        std::string subs = str.substr(i, strlen);
        int numPi = getPi(subs);
        maximum = std::max(maximum, numPi);
    }
    std::cout << maximum << std::endl;
}