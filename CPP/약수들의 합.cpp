#include <cstdio>
#include <iostream>
#include <vector>

void print(std::vector<int> vec) {
    int sz = vec.size();
    for(int i=0; i<sz; i++) {
        if(i == sz-1) {
            printf("%d\n", vec[i]);
        } else printf("%d + ", vec[i]);
    }
}

int main() {
    while(1) {
        int n, sum = 0;
        std::cin >> n;
        if(n == -1) break;
        std::vector<int> yaks;
        for(int i=1; i<n; i++) {
            if(n % i == 0) {
                yaks.push_back(i);
                sum += i;
            }
        }
        if(sum == n) {
            printf("%d = ", n);
            print(yaks);
        } else {
            std::cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}