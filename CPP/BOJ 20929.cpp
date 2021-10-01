#include <bits/stdc++.h>

using namespace std;

#define FASTIO FAST_IO()
#define FLUSH cout << flush

void FAST_IO() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
}
// function : 입출력 속도 향상

// Definitions

// typedefs

// Global Variables

// functions

int ask(char which, int index) {
    int ret;
    cout << "? " << which << " " << index+1 << "\n";
    FLUSH;
    cin >> ret;
    return ret;
}

int func(int n) {
    int amax = ask('A', n-1);
    int bmax = ask('B', n-1);
    char a = (amax <= bmax) ? 'A' : 'B';
    char b = a == 'A' ? 'B' : 'A';
    int l = 0, r = n-2, m = (l + r)/2;
    int median = min(amax, bmax);
    while(l <= r) {
        m = (l+r)/2;
        int va = ask(a, m);
        int vb = ask(b, n-2-m);
        median = min(median, max(va, vb));
        if(va > vb) r = m-1;
        else l = m+1;
    }
    return median;
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    auto median = func(n);
    cout << "! " << median << '\n';
    FLUSH;
    return 0;
}