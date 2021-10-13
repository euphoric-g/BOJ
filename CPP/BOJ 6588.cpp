#include <iostream>
#include <vector>

using namespace std;

int sieve[1000001] = {0, };

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    for(int i=2; i<=1000000; i++) {
        if(sieve[i]) continue;
        for(int j=2*i; j<=1000000; j+=i) sieve[j] = 1;
    }
    vector<int> prime;
    for(int i=3; i<=1000000; i++) if(!sieve[i]) prime.push_back(i);
    while(cin >> n) {
        if(n == 0) break;
        bool find = false;
        for(int i=0; i<prime.size() && !find; i++) {
            if(prime[i] > n) break;
            if(!sieve[n-prime[i]]) {
                find = true;
                cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
            }
        }
        if(!find) cout << "Goldbach's conjecture is wrong.\n";
    }
}