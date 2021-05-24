#include <iostream>
#include <string>
#include <vector>

int *pi;

void getPi(std::string str) {
    int j = 0;
    int strlen = str.size();
    for(int i=1; i<=strlen; i++) {
        while(j > 0 && str[i] != str[j]) {
            j = pi[j-1];
        }
        if(str[i] == str[j]) {
            pi[i] = ++j;
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string pn = "I";
    for(int i=0; i<n; i++) {
        pn.append("OI");
    }
    int pnlen = pn.size();
    std::string str;
    std::cin >> str;
    pi = new int[pnlen+1];
    for(int i=0; i<pnlen; i++) pi[i] = 0;
    getPi(pn);
    int strlen = str.size();
    int j = 0;
    int cnt = 0;
    for(int i=0; i<strlen; i++) {
        while(j > 0 && str[i] != pn[j]) {
            j = pi[j-1];
        }
        if(str[i] == pn[j]) {
            j++;
            if(j == pnlen) {
                j = pi[j-1];
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
    delete pi;
    return 0;
}