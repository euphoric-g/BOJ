#include <iostream>

int main() {
    long long a, b, c;
    std::cin >> a >> b >> c;
    long long m = a * b * c;
    int cnt[10] = {0, };
    while(m != 0) {
        cnt[m % 10]++;
        m /= 10;
    }
    for(int i=0; i<10; i++) {
        std::cout << cnt[i] << "\n";
    }
    return 0;
}