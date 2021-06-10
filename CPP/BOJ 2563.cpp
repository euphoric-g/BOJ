#include <iostream>

#define BLANK 0
#define COVERED 1

int main() {
    int arr[100][100];
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) arr[i][j] = BLANK;
    }
    int n;
    std::cin >> n;
    while(n--) {
        int a, b;
        std::cin >> a >> b;
        for(int i=a; i<a+10; i++) {
            for(int j=b; j<b+10; j++) {
                arr[i][j] = COVERED;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) if(arr[i][j] == COVERED) cnt++;
    }
    std::cout << cnt << '\n';
}