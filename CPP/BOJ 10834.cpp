#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int dir = 0, ratio = 1;
    for(int i=0; i<n; i++) {
        int r1, r2, d;
        cin >> r1 >> r2 >> d;
        ratio = ratio / r1 * r2;
        if(d) dir = !dir;
    }
    cout << dir << ' ' << ratio << '\n';
}