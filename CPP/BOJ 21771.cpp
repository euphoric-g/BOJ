#include <iostream>
#include <string>
#include <vector>

int main() {
    int r, c;
    int rg, cg, rp, cp;
    std::cin >> r >> c;
    std::cin >> rg >> cg >> rp >> cp;
    std::vector<std::string> vec;
    for(int i=0; i<r; i++) {
        std::string str;
        std::cin >> str;
        vec.push_back(str);
    }
    int pc = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(vec[i][j] == 'P') {
                pc++;
            }
        }
    }
    if(pc == rp * cp) {
        std::cout << "0\n";
        return 0;
    } else {
        std::cout << "1\n";
        return 0;
    }
}