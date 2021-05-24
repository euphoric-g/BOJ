#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for(int i=0; i<t; i++) {
        int yonsei = 0;
        int korea = 0;
        for(int j=0; j<9; j++) {
            int y, k;
            std::cin >> y >> k;
            yonsei += y;
            korea += k;
        }
        if(yonsei > korea) std::cout << "Yonsei\n";
        else if(korea > yonsei) std::cout << "Korea\n";
        else std::cout << "Draw\n";
    }
    return 0;
}