#include <iostream>
#include <stack>
#include <vector>

int n;

class BigInt {
    public:
    int arr[200];
    bool carry[200];
    void x2() {
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
    void m1() {
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
void move(int from, int to, int other, int size) {
    if(size == 1) {
        std::cout << from+1 << ' ' << to+1 << '\n';
    } else {
        move(from, other, to, size-1);
        move(from, to, other, 1);
        move(other, to, from, size-1);
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin >> n;
    BigInt(n).show();
    if(n <= 20) move(0, 2, 1, n);
    return 0;
}