#include <iostream>

using namespace std;

int main() {
    int a, b, n, q;
    cin >> a >> b >> n;
    a %= b;
    while(n--) {
        a *= 10;
        q = a/b;
        a %= b;
    }
    cout << q << '\n';
}