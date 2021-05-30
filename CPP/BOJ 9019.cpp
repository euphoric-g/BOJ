#include <iostream>

class Calculator {
    public:
    int n;
    int digit[4];
    Calculator() {}
    Calculator(int in) {
        n = in;
        apply_n(n);
    }
    void apply_n() {
        n %= 10000;
        digit[0] = n % 10;
        digit[1] = (n / 10) % 10;
        digit[2] = (n / 100) % 10;
        digit[3] = (n / 1000) % 10;
    }
    void apply_digit() {
        n = digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0];
    }
    void R() {
        int temp = digit[0];
        digit[0] = digit[1];
        digit[1] = digit[2];
        digit[2] = digit[3];
        digit[3] = temp;
        apply_digit();
    }
    void L() {
        int temp = digit[0];
        digit[0] = digit[3];
        digit[3] = digit[2];
        digit[2] = digit[1];
        digit[1] = temp;
        apply_digit();
    }
    void D() {
        n *= 2;
        apply_n();
    }
    void S() {
        n %= 10000;
        if(--n == -1) n = 9999;
        apply_n();
    }
};

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int a, b;
        std::cin >> a >> b;
    }
}