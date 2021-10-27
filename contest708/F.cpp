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

namespace pq_cmp {
    struct int_min { bool operator()(const int &a, const int &b) { return a > b; } };
    struct int_max { bool operator()(const int &a, const int &b) { return a < b; } };
    struct pii_011 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first < b.first; return a.second < b.second; } };
    struct pii_010 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first < b.first; return a.second > b.second; } };
    struct pii_001 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first > b.first; return a.second < b.second; } };
    struct pii_000 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first > b.first; return a.second > b.second; } };
    struct pii_111 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second < b.second; return a.first < b.first; } };
    struct pii_110 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second < b.second; return a.first > b.first; } };
    struct pii_101 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second > b.second; return a.first < b.first; } };
    struct pii_100 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second > b.second; return a.first > b.first; } };
};
// function : 데이터타입이 int, pair<int, int>인 우선순위 큐를 위한 비교 함수셋

typedef priority_queue<int, vint, pq_cmp::int_min> pq_min;
typedef priority_queue<int, vint, pq_cmp::int_max> pq_max;

const double PI = acos(-1);

void FAST_IO() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
}
// function : 입출력 속도 향상

size_t STR_FIND(string str, char c) { return str.find(c, 0); }
size_t STR_FIND(string str, char c, int start) { return str.find(c, start); }
// function : 문자열에서 특정 문자 검색 후 위치 반환

string SUBSTR(string str, int start, int len) { return str.substr(start, len); }
string SUBSTR(string str, int start) { return str.substr(start, SIZE(str)); }
// function : 문자열의 하위 문자열 반환

vstr PARSE(string str, char delim) {
    vector<string> ret;
    while(!str.empty()) {
        auto it = STR_FIND(str, delim, 0);
        if(it == string::npos) {
            ret.push_back(str);
            break;
        }
        ret.push_back(SUBSTR(str, 0, it));
        str = SUBSTR(str, it+1);
    }
    return ret;
}
// function : 문자열을 특정 문자기준으로 파싱

vvint INIT_VVINT(int n, int m, int init) {
    vvint ret;
    REP(i, 0, n) ret.push_back(vint(m, init));
    return ret;
}
// function : init으로 초기화된 n*m 크기의 vector<vector<int>> 반환

vvint GET_2D(int &n, int &m) {
    cin >> n >> m;
    vvint ret(n);
    REP(i, 0, n) {
        ret[i] = vint(m);
        REP(j, 0, m) cin >> ret[i][j];
    }
    return ret;
}
// function : 정수 n*m개를 입력받아 n*m 크기의 vector<vector<int>> 형태로 반환

string GET_ONE_LINE() {
    string ret;
    getline(cin, ret);
    return ret;
}
// function : 공백 관계없이 한 줄을 입력받아 문자열로 반환

vint GET_N_INTS(int n) {
    vector<int> ret = vint(n, 0);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}
// function : 정수 n개를 입력받아 vector<int> 형태로 반환

vpii GET_N_PII(int n) {
    vector<pair<int, int>> ret;
    REP(i, 0, n) {
        int a, b;
        cin >> a >> b;
        ret.push_back({a, b});
    }
    return ret;
}
// function : n개의 정수 쌍을 입력받아 vector<pair<int, int>> 형태로 반환

vstr GET_N_STR(int n) {
    vector<string> ret = vstr(n);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}
// function : n개의 문자열을 입력받아 vector<string> 형태로 반환

vint VINT_SUM(vint a, vint b) { REP(i, 0, SIZE(a)) a[i] += b[i]; return a; }
// function : 크기가 같은 두 vint를 더한 벡터를 반환

int SUM_OF_VINT(vint &a) { int sum = 0; REP(i, 0, SIZE(a)) sum += a[i]; return sum; }
// function : vint의 모든 원소 합을 반환

vint VINT_NATURAL(int n) {
    vint ret(n);
    REP(i, 0, n) ret[i] = i+1;
    return ret;
}
// function : 1 부터 n 까지의 자연수를 순서대로 원소로 가지는 vint 반환

vint STR_TO_VINT(string &s) {
    vint ret;
    FOREACH(it, s) ret.push_back(*it-'0');
    return ret;
}
// function : 숫자로 이루어진 문자열의 각 자리수를 원소로 가지는 vint 반환

class UnionFind {
    public:
    vint root;
    UnionFind() {}
    UnionFind(int n) {
        root = vint(n, -1);
    }
    int find_root(int v) {
        if(root[v] == -1) return v;
        return root[v] = find_root(root[v]);
    }
    void merge(int v, int w) { root[find_root(v)] = find_root(w); }
};

class Trie {
    /*
    필요한 곳에서 Trie root = Trie(0); 으로 선언 후
    필요한 단어들을 root에 삽입
    아호-코라식 : root.Init(); 으로 failure_link 설정 후 사용
    */
    public:
    bool is_root = false, finish = false;
    char ch = 'R';
    map<char, Trie> next;
    Trie *failure_link;
    Trie() { is_root = true; }
    Trie(char c) { ch = c; }
    bool exist(char to_find) { return next.find(to_find) != next.end(); }
    Trie *find(char to_find) {
        if(!exist(to_find)) { next[to_find] = Trie(to_find); }
        return &next[to_find];
    }
    void insert(string &word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            cur = cur->find(word[cursor++]);
        }
        cur->finish = true;
    }
    bool search(string &word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            if(!cur->exist(word[cursor])) return false;
            cur = &cur->next[word[cursor++]];
        }
        return cur->finish;
    }
    void explore(string s) {
        if(finish) cout << s << '\n';
        for(auto &n : next) n.second.explore(s + n.second.ch);
    }
    void init_Aho_Corasick() {
        Trie *root = this;
        queue<Trie *> q;
        q.push(root);
        while(!q.empty()) {
            Trie *cur = q.front(); q.pop();
            for(auto &ch : cur->next) {
                Trie *next = &ch.second;
                if(cur == root) next->failure_link = root;
                else {
                    Trie *prev = cur->failure_link;
                    while(prev != root && prev->next.find(ch.first) == prev->next.end()) prev = prev->failure_link;
                    if(prev->next.find(ch.first) != prev->next.end()) prev = &prev->next[ch.first];
                    next->failure_link = prev;
                }
                if(next->failure_link->finish) next->finish = true;
                q.push(next);
            }
        }
    }
    int search_Aho_Corasick(string text) {
        Trie *root = this, *cur = this;
        int cnt = 0;
        int n = text.size();
        REP(i, 0, n) {
            while(cur != root && cur->next.find(text[i]) == cur->next.end()) cur = cur->failure_link;
            if(cur->next.find(text[i]) != cur->next.end()) cur = &cur->next[text[i]];
            if(cur->finish) ++cnt;
        }
        return cnt;
    }
};
// Data Structure : Trie

class SegTree_MAX {
    public:
    vector<ll> arr;
    vector<ll> tree;
    SegTree_MAX(vector<ll> arrin) {
        arr = arrin;
        tree.resize(1 << (1 + (int)ceil(log2(arr.size()))));
        init(0, arr.size()-1, 1);
    }
    ll init(int s, int e, int n) {
        if(s == e) return tree[n] = arr[s];
        int m = (s+e)/2;
        return tree[n] = MAX(init(s, m, n*2), init(m+1, e, n*2+1));
    }
    ll max_val(int s, int e, int l, int r, int n) {
        if(e < l || r < s) return INT32_MIN;
        if(l <= s && e <= r) return tree[n];
        if(s != e) {
            int m = (s+e)/2;
            return MAX(max_val(s, m, l, r, n*2), max_val(m+1, e, l, r, n*2+1));
        }
    }
};
class SegTree_MAX_AREA {
    /*
    vector<ll>을 인자로 하여 생성
    생성 후 별도의 처리 없이 max_area 값 이용
    */
    public:
    vector<ll> arr;
    vector<ll> tree;
    int arrlen, tree_height, tree_size;
    ll max_area;
    SegTree_MAX_AREA() {}
    SegTree_MAX_AREA(vector<ll> arrin) {
        arr = arrin;
        arrlen = arr.size();
        max_area = 0;
        tree_height = (int)ceil(log2(arrlen));
        tree_size = 1 << (tree_height + 1);
        arr.resize(arrlen+1);
        tree.resize(tree_size);
        init(0, arrlen-1, 1);
        arr[arrlen] = INT64_MAX;
        find(0, arrlen-1);
    }
    ll init(int start, int end, int node) {
        if(start == end) return tree[node] = start;
        int mid = (start + end)/2;
        ll left = arr[init(start, mid, node*2)];
        ll right = arr[init(mid+1, end, node*2+1)];
        return tree[node] = ((left <= right) ? tree[node*2] : tree[node*2+1]);
    }
    ll min_val(int start, int end, int left, int right, int node) {
        if(right < start || end < left) return arrlen;
        if(left <= start && end <= right) return tree[node];
        int mid = (start + end)/2;
        ll left_val = min_val(start, mid, left, right, node*2);
        ll right_val = min_val(mid+1, end, left, right, node*2+1);
        return (arr[left_val] <= arr[right_val] ? left_val : right_val);
    }
    void find(int left, int right) {
        if(left > right) return;
        ll min_index = min_val(0, arrlen-1, left, right, 1);
        max_area = std::max(max_area, arr[min_index] * (right - left + 1));
        if(left != right) {
            find(left, min_index-1);
            find(min_index+1, right);
        }
    }
};
// Data Structure : Segment Tree (최대값, 히스토그램 최대 넓이)

class TSP {
    /*
    n x n 정수 cost 배열을 인자로 입력 후 exec(0, 1) 값 확인 (n <= 16)
    */
    public:
    int n;
    const int MAX_VALUE = 100'000'000;
    int cost[16][16], dp[16][1 << 16];
    TSP() {}
    TSP(vector<vector<int>> _cost) {
        n = _cost.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) cost[i][j] = _cost[i][j];
            for(int j=0; j<(1 << n); j++) dp[i][j] = 0;
        }
    }
    int add(int bit, int x) {
        int ans = bit |= 1 << x;
        return ans;
    }
    int visit(int bit, int x) {
        int ans = bit &= 1 << x;
        return ans != 0;
    }
    int exec(int start, int bit) {
        if(bit == (1<<n) - 1 && cost[start][0] != 0) {
            dp[start][bit] = cost[start][0];
            return dp[start][bit];
        } else if(dp[start][bit] != 0) {
            return dp[start][bit];
        } else  {
            int limit = -1;
            for(int i=0; i<n; i++) {
                if(visit(bit, i) == 1) continue;
                if(cost[start][i] == 0) continue;
                limit = limit == -1 ?  exec(i, add(bit, i))+cost[start][i] : min(limit, exec(i, add(bit, i))+cost[start][i]);
            }
            dp[start][bit] = limit == -1 ? MAX_VALUE : limit;
            return dp[start][bit];
        }
    }
};
// Algorithm : Traveling Salesman Problem(TSP)

int builtout_popcount(int n) {
    int ret = 0;
    REP(i, 0, 32) if((n >> i) % 2) ++ret;
    return ret;
}
int builtout_popcount(ll n) {
    int ret = 0;
    REP(i, 0, 64) if((n >> i) % 2) ++ret;
    return ret;
}
int builtout_popcount(ull n) {
    int ret = 0;
    REP(i, 0, 64) if((n >> i) % 2) ++ret;
    return ret;
}
// Function : 인자에 포함된 비트 1의 개수를 반환

vint kmp(string &str) {
    vint ret(str.size());
    int j = 0;
    for(int i=1; i<str.size(); i++) {
        while(j > 0 && str[i] != str[j]) j = ret[j-1];
        if(str[i] == str[j]) ret[i] = ++j;
    }
    return ret;
}
// Algorithm : KMP

pair<int, vvint> knapsack(int n, vint weight, vint values, int bag_size) {
    // 물건 개수 n, 무게 배열 weight, 가치 배열 values, 가방 크기 bag_size
    // dp 배열과 최대 가치 반환
    vvint ret = INIT_VVINT(n, bag_size+1, 0);
    REP(i, 0, n) {
        if(i == 0) REP(j, weight[i], bag_size+1) ret[i][j] = values[i];
        else REP(j, 0, bag_size+1) ret[i][j] = (weight[i] <= j) ? max(values[i] + ret[i-1][j-weight[i]], ret[i-1][j]) : ret[i-1][j];
    }
    return {ret[n-1][bag_size], ret};
}
pair<int, vint> knapsack_light(int n, vint &weight, vint &values, int bag_size) {
    vint dp(bag_size+1, 0);
    REP(i, 0, n) {
        REPREV(j, bag_size, weight[i]) {
            if(dp[j-weight[i]]) dp[j] = dp[j] > dp[j-weight[i]] + values[i] ? dp[j] : dp[j-weight[i]] + values[i];
        }
        dp[weight[i]] = max(dp[weight[i]], values[i]);
    }
    return {MAX_ELEMENT(dp), dp};
}
// Algorithm : Knapsack Problem

void FFT(vector<cpx> &arr, bool invert) {
    int n = SIZE(arr);
    for(int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for( ; j>=bit; bit>>=1) j -= bit; j+= bit;
        if(i < j) swap(arr[i], arr[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        double angle = 2*PI/len*(invert ? -1 : 1);
        cpx wlen(cos(angle), sin(angle));
        for(int i=0; i<n; i+=len) {
            cpx w(1, 0);
            for(int j=0; j<len/2; j++) {
                cpx u = arr[i+j], v = arr[i+j+len/2] * w;
                arr[i+j] = u+v;
                arr[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if(invert) REP(i, 0, n) arr[i] /= n;
}
vint FFT_multiply(vint a, vint b) {
    vector<cpx> fa(ALL(a)), fb(ALL(b));
    int n = 1;
    while(n < max(SIZE(a), SIZE(b))) n <<= 1; n <<= 1;
    fa.resize(n), fb.resize(n); FFT(fa, false); FFT(fb, false);
    REP(i, 0, n) fa[i] *= fb[i]; FFT(fa, true);
    vint res(n, 0);
    REP(i, 0, n) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
    return res;
}
// Algorithm : Fast Fourier Transform(FFT)
// Reference : blog.myungwoo.kr/54

int binary_do_lower(int start, int end, bool (*func)(int)) {
    // func 값이 처음으로 false가 되는 값 탐색
    // 필요시 func 인자 변경
    while(start < end) {
        int mid = (start + end)/2;
        if(!func(mid)) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    return start;
}
// Function : 이분탐색으로 특정 조건을 만족하는 가장 작은 수 찾기

vint LIS_dp(vint &arr) {
    vint dp(SIZE(arr), 1);
    REP(i, 0, SIZE(arr)) REP(j, 0, i) if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
    return dp;
}
int LIS_light(vint& arr) {
    vint ret;
    ret.push_back(arr[0]);
    REP(i, 1, SIZE(arr)) {
        auto it = lower_bound(ALL(ret), arr[i]);
        if((it - ret.begin()) < SIZE(ret)) *it = arr[i];
        else ret.push_back(arr[i]);
    }
    return SIZE(ret);
}
vint LIS_tracking(vint &arr) {
    vint lis(SIZE(arr)), mlis(SIZE(arr));
    int idx = 1;
    REP(i, 0, SIZE(arr)) {
        if(arr[i] > lis[idx-1]) {
            lis[idx++] = arr[i];
            mlis[i] = idx;
        } else {
            int nidx = lower_bound(lis.begin(), lis.begin() + idx, arr[i]) - lis.begin();
            lis[nidx] = arr[i];
            mlis[i] = nidx+1;
        }
    }
    vint ans;
    REPREV(i, SIZE(arr)-1, 0) if(mlis[i] == idx) { ans.push_back(arr[i]); --idx; }
    REV(ans);
    return ans;
}
// Algorithm : Longest Increasing Subsequence(LIS)

pair<ll,pll> xGCD(ll a, ll b) {
    if(b == 0) return {a,{1,0}};
    pair<ll,pair<ll,ll>> ret = xGCD(b, a%b);
    ll g, x, y;
    g = ret.first;
    tie(x,y) = ret.second;
    return {g,{y,x-(a/b)*y}};   
}

pll CRT(vll &M, vll &A) {
    // x == A (mod M)
    typedef __int128_t i128;
    if(A.size() != M.size()) return {-1,-1};
    int N = A.size();
    ll a1 = A[0], m1 = M[0];
    a1 %= m1;
    for(int i=1;i<N;++i) {
        ll a2 = A[i], m2 = M[i], g = __gcd(m1, m2);
        if(a1 % g != a2 % g) return {-1,-1};
        ll p, q;
        auto res = xGCD(m1/g, m2/g);
        tie(p,q) = res.second;
        i128 mod = (i128)m1 / g * m2;
        a1 = ((i128)a1 * (m2/g) % mod) * q % mod + ((i128)a2*(m1/g)%mod)*p % mod;
        a1 = (a1 + mod) % mod;
        m1 = mod;
    }
    return {a1, m1};
}
// Algorithm : Chinese Remainder Theorem(CRT)
// reference : forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli/

// Definitions

// typedefs

// Global Variables
ll dp[1000001][2];
const ll MOD = 1e9+7;
// functions

int main() {
    FASTIO;
    int t;
    cin >> t;
    dp[0][0] = 1, dp[0][1] = 2;
    REP(i, 1, 1000001) {
        dp[i][0] = (dp[i-1][0] * 3 + dp[i-1][1] * 2) % MOD;
        dp[i][1] = (dp[i-1][0] * 2 + dp[i-1][1] * 2) % MOD;
    }
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n][0] << '\n';
    }
}