#include <iostream>

int main() {
    int cnt = 0;
    for(int i=0; i<6; i++) {
        char get;
        std::cin >> get;
        if(get == 'W') cnt++;
    }
    if(cnt >= 5) std::cout << "1\n";
    else if(cnt >= 3) std::cout << "2\n";
    else if(cnt >= 1) std::cout << "3\n";
    else std::cout << "-1\n";
    return 0;
}