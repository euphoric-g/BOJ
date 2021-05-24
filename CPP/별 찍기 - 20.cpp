#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n; j++) {
            if((i+j)%2) {
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}