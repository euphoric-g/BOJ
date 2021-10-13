#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sieve[2000001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int i=2; i<=2000000; i++) {
        if(sieve[i]) continue;
        for(int j=2*i; j<=2000000; j+=i) sieve[j] = 1;
    }
    vector<int> prime;
    for(int i=2; i<=2000000; i++) if(!sieve[i]) prime.push_back(i);
    while(t--) {
        long long a, b;
        cin >> a >> b;
        if(a+b <= 3) { cout << "NO\n"; continue; }
        if((a+b) % 2 == 0) cout << "YES\n";
        else {
            if(a+b <= 2000000) cout << (sieve[a+b-2] == 0 ? "YES\n" : "NO\n");
            else {
                bool find = false;
                for(int i=0; i<prime.size() && !find; i++) {
                    if((a+b-2)%prime[i] == 0) find = true;
                }
                cout << (find ? "NO\n" : "YES\n");
            }
        }
    }
}