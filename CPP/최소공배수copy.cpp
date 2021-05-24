#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define endl "\n"
#define pb push_back
#define all(X) begin((X)), end((X))
#define sz(X) (int)(X).size()
#define fi first
#define se second
#define fv(X) for(auto&_:(X))cin>>_
#define fv2(X) for(auto&_1:(X))for(auto&_2:_1)cin>>_2

void solve() {
   ll a, b;
   cin >> a >> b;
   cout << lcm(a, b) << endl;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TT;
   cin >> TT;
   while (TT--)
      solve();
   return 0;
}