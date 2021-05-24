#include <iostream>
#include <vector>
#include <string>

class BigInt {
    public:
    int arr[200];
    bool carry[200];
    BigInt multiply2(BigInt &a) {
        for(int i=0; i<200; i++) carry[i] = false;
        for(int i=0; i<200; i++) {
            arr[i] *= 2;
            if(arr[i] > 9) {
                arr[i] -= 10;
                carry[i+1] = true;
            }
        }
        for(int i=0; i<200; i++) {
            if(carry[i]) {
                arr[i]++;
            }
        }
    }
    BigInt minus() {
        arr[0]--;
    }
    void show() {
        int cur = 199;
        while(arr[cur] == 0) cur--;
        for(int i=cur; i>=0; i--) {
            std::cout << arr[i];
        }
        std::cout << '\n';
    }
    BigInt() {}
    BigInt(int pow) {
        for(int i=0; i<200; i++) {
            arr[i] = 0;
            carry[i] = false;
        }
        arr[0] = 1;
        for(int i=0; i<pow; i++) {
            x2();
        }
        m1();
    }
};

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
}