#include <iostream>

int arr[50];

int main() {
    int t;
    std::cin >> t;
    for(int i=0; i<50; i++) {
        arr[i] = (i * (i+1))/2;
    }
    while(t-->0) {
        int k;
        bool find = false;
        std::cin >> k;
        for(int a=1; a<50 && !find; a++) {
            if(arr[a] > k) break;
            for(int b=1; b<50 && !find; b++) {
                if(arr[a] + arr[b] > k) break;
                for(int c=1; c<50 && !find; c++) {
                    if(arr[a] + arr[b] + arr[c] > k) break;
                    if(arr[a]+arr[b]+arr[c] == k) {
                        find = true;
                        std::cout << "1\n";
                        continue;
                    }
                }
            }
        }
        if(!find) std::cout << "0\n";
    }
}