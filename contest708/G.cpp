#include <bits/stdc++.h>

/*
    C++ Template by LJH
    Last Update : 21/10/10
*/

using namespace std;

#define FASTIO FAST_IO()
#define ENDL cout << '\n'
#define MAX(a, b) max((a), (b))
#define MIN(a, b) min((a), (b))
#define MAX3(a, b, c) max(max((a), (b)), (c))
#define MIN3(a, b, c) min(min((a), (b)), (c))
#define ALL(v) (v).begin(), (v).end()
#define ALL_REV(v) (v).rbegin(), (v).rend()
#define UNIQUE(v) unique(ALL(v))
#define UNIQUE_ERASE(v) (v).erase(UNIQUE(v), (v).end())
#define FOREACH(it, v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define REPREV(i, a, b) for(int i=(a); i>=(b); --i)
#define SIZE(v) ((int)v.size())
#define POPCOUNT(n) (builtout_popcount(n))
#define LOWERBOUND(v, x) lower_bound(ALL(v), (x))
#define UPPERBOUND(v, x) upper_bound(ALL(v), (x))
#define REV(v) reverse(ALL(v))
#define SORT(v) sort(ALL(v))
#define SORT_REV(v) sort(ALL_REV(v))
#define MAX_ELEMENT(v) *max_element(ALL(v))
#define MIN_ELEMENT(v) *min_element(ALL(v))
#define SWAP(a, b) swap((a), (b))
#define DO_PERMUTATION(func, v) do {func;} while(next_permutation(ALL(v)))
#define DO_PREV_PERMUTATION(func, v) do {func;} while(prev_permutation(ALL(v)))
#define GCD(v) gcd(v)
#define LCM(v) lcm(v)
#define PRINT(v) REP(i, 0, SIZE(v)) cout << v[i] << ' '; ENDL
#define PRINTLN(v); REP(i, 0, SIZE(v)) { cout << v[i]; ENDL; }
#define N_TIMES(n) REP(i, 0, n)
#define VBOOL(n, b) vector<bool>(n, b)
#define DOUBLE_PRECISION(n) cout << fixed << setprecision(n)

// For interactive problems
#define FLUSH cout << flush

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<pii, int> piii;
typedef tuple<int, int, int> tiii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<pis> vpis;
typedef vector<pss> vpss;
typedef complex<double> cpx;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, string> umis;

const double PI = acos(-1);

void FAST_IO() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
}
// function : 입출력 속도 향상

vint GET_N_INTS(int n) {
    vector<int> ret = vint(n, 0);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}
// function : 정수 n개를 입력받아 vector<int> 형태로 반환

// Definitions

// typedefs

// Global Variables
int dp[100][1 << 10];
// functions

int main() {
    FASTIO;
    int n, m, max_xor = 0;
    cin >> n >> m;
    auto vec = GET_N_INTS(n);
    REP(i, 0, n) vec[i] = abs(vec[i]);
    dp[0][vec[0]] = 1;
    dp[0][0] = 1;
    REP(i, 1, n) {
        dp[i][vec[i]] = 1;
        REP(j, 0, 1 << 10) {
            if(dp[i-1][j] > 0) {
                dp[i][j] = dp[i][j] > 0 ? min(dp[i][j], dp[i-1][j]) : dp[i-1][j];
                dp[i][j ^ vec[i]] = dp[i-1][j^vec[i]] > 0 ? min(dp[i-1][j^vec[i]], 1 + dp[i-1][j]) : dp[i-1][j] + 1;
            }
        }
    }
    vint ans;
    REP(i, 0, 1 << 10) {
        if(dp[n-1][i] > 0 && dp[n-1][i] <= m) ans.push_back(i);
    }
    int anss = 0;
    FOREACH(it, ans) {
        if((m - dp[n-1][*it]) % 2 == 0) anss = max(anss, *it);
        else {
            FOREACH(it2, ans) {
                anss = max(anss, (*it)^(*it2));
            }
        }
    }
    cout << anss << '\n';
    return 0;
}