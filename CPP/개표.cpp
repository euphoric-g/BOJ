#include <iostream>
#include <string>

int main() {
    int v, s = 0;
    std::cin >> v;
    std::string str;
    std::cin >> str;
    for(int i=0; i<v; i++) {
        if(str[i] == 'A') s++;
        else s--;
    }
    if(s>0) {
        std::cout << "A\n";
    } else if(s == 0) {
        std::cout << "Tie\n";
    } else {
        std::cout << "B\n";
    }
    return 0;
}