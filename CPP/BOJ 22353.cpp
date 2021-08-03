#include <iostream>
#include <iomanip>

int main() {
    int a, d, k;
    std::cin >> a >> d >> k;
    double sum = 0.0;
    int min = a;
    double prob = 1.0;
    double win = d / 100.0;
    while(prob > 0.00000000000001) {
        sum += prob * win * min;
        min += a;
        prob *= 1 - win;
        win *= 1 + k/100.0;
        if(win >= 1.0) win = 1.0;
    }
    std::cout << std::fixed << std::setprecision(9) << sum << '\n';
}