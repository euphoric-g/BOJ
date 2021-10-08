#include <iostream>
#include <algorithm>

int arr[21][21][21];

int func(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if(a > 20 || b > 20 || c > 20) {
        return func(20, 20, 20);
    }
    if(arr[a][b][c] != 0) return arr[a][b][c];
    if(a < b && b < c) {
        int ans = func(a, b, c-1) + func(a, b-1, c-1) - func(a, b-1, c);
        arr[a][b][c] = ans;
        return ans;
    } else {
        int ans = func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) - func(a-1, b-1, c-1);
        arr[a][b][c] = ans;
        return ans;
    }
}

int main() {
    int a, b, c;
    for(int i=0; i<21; i++) {
        for(int j=0; j<21; j++) {
            for(int k=0; k<21; k++) {
                arr[i][j][k] = 0;
            }
        }
    }
    while(1) {
        int ans;
        std::cin >> a >> b >> c;
        if( a == -1 && b == -1 && c == -1 ) break;
        else ans = func(a, b, c);
        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << std::endl;
    }
    return 0;
}