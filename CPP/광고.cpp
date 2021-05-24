#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::string str;
int *prep;

int main() {
    int l;
    std::cin >> l;
    prep = new int[l];
    for(int i=0; i<l; i++) prep[i] = 0;
    std::cin >> str;
    int j = 0;
    for(int i=1; i<l; i++) {
        while(j > 0 && str[i] != str[j]) {
            j = prep[j-1];
        }
        if(str[i] == str[j]) {
            prep[i] = ++j;
        }
    }
    std::cout << l - prep[l-1] << std::endl;
    delete prep;
    return 0;
}