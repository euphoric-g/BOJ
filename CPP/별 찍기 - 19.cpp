#include <iostream>

int n;
bool arr[400][400];

void func(int s, int e, int n) {
    for(int i=s; i<=e; i++) {
        arr[s][i] = true;
        arr[e][i] = true;
        arr[i][s] = true;
        arr[i][e] = true;
    }
    if(s != e) {
        func(s+2, e-2, n-1);
    }
}

int main() {
    std::cin >> n;
    func(0, 4*n-3-1, n);
    for(int i=0; i<4*n-3; i++) {
        for(int j=0; j<4*n-3; j++) {
            std::cout << (arr[i][j] ? '*' : ' ');
        }
        std::cout << '\n';
    }
    return 0;
}