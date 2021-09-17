#include <bits/stdc++.h>

/*
    C++ Template by LJH

    Last Update : 21/09/17

    Macros
    FASTIO, MAX, MIN, ALL, UNIQUE, UNIQUE_ERASE, FOREACH, REP, POPCOUNT(int, ll), BINSEARCH,
    LOWERBOUND, UPPERBOUND, SORT, SORT_REV, MAX_ELEMENT, MIN_ELEMENT, SWAP, DO_PERMUTATION,
    DO_PREV_PERMUTATION, GCD, LCM, VINT(vector<int> with n inits), PRINT
    
    Data Structures
    Segment Tree(for max histogram area, max value), priority_queue(with various comp func)

    Algorithm

    KMP, Trie, FFT(Fast Fourier Transform), TSP(Traveling Salesman Problem),
    LIS(Longest Increasing Subsequence), (Euler-Phi)
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
#define SIZE(v) ((int)v.size())
#define POPCOUNT(n) (builtout_popcount(n))
#define LOWERBOUND(v, x) lower_bound(ALL(v), (x))
#define UPPERBOUND(v, x) upper_bound(ALL(v), (x))
#define REV(v) reverse(ALL(v))
#define SORT(v) sort(ALL(v))
#define SORT_REV(v) sort(ALL_REV(v))
#define MAX_ELEMENT(v) max_element(ALL(v))
#define MIN_ELEMENT(v) min_element(ALL(v))
#define SWAP(a, b) swap((a), (b))
#define DO_PERMUTATION(func, v) do {func;} while(next_permutation(ALL(v)))
#define DO_PREV_PERMUTATION(func, v) do {func;} while(prev_permutation(ALL(v)))
#define GCD(v) gcd(v)
#define LCM(v) LCM(v)
#define VINT(n, init) vector<int>(n, init)
#define VSTR(n) vector<string>(n)
#define PRINT(v) REP(i, 0, SIZE(v)) cout << v[i] << ' '; ENDL
#define PRINTLN(v); REP(i, 0, SIZE(v)) { cout << v[i]; ENDL; }
#define N_TIMES(n) REP(i, 0, n)
#define VBOOL(n, b) vector<bool>(n, b)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef vector<pii> vpii;
typedef vector<pis> vpis;
typedef vector<pss> vpss;
typedef complex<double> cpx;

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

typedef priority_queue<int, vint, pq_cmp::int_min> pq_min;
typedef priority_queue<int, vint, pq_cmp::int_max> pq_max; 

void FAST_IO() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
}

size_t STR_FIND(string str, char c) { return str.find(c, 0); }
size_t STR_FIND(string str, char c, int start) { return str.find(c, start); }
string SUBSTR(string str, int start, int len) { return str.substr(start, len); }
string SUBSTR(string str, int start) { return str.substr(start, SIZE(str)); }
vector<string> PARSE(string str, char delim) {
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

vvint INIT_VVINT(int n, int m, int init) {
    vvint ret;
    REP(i, 0, n) ret.push_back(VINT(m, init));
    return ret;
}

string GET_ONE_LINE() {
    string ret;
    getline(cin, ret);
    return ret;
}

vector<int> GET_N_INTS(int n) {
    vector<int> ret = VINT(n, 0);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}

vector<pair<int, int>> GET_N_PII(int n) {
    vector<pair<int, int>> ret;
    REP(i, 0, n) {
        int a, b;
        cin >> a >> b;
        ret.push_back({a, b});
    }
    return ret;
}

vector<string> GET_N_STR(int n) {
    vector<string> ret = VSTR(n);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}

const double PI = acos(-1);

class Trie {
    /*
    필요한 곳에서 Trie root = Trie(0); 으로 선언 후
    필요한 단어들을 root에 삽입
    적절한 후처리는 구현 필요
    */
    public:
    bool is_root = false, finish = false;
    char ch;
    map<char, Trie> next;
    Trie() {is_root = false;}
    Trie(int i) {is_root = true;}
    Trie *find(char to_find) {
        if(next.find(to_find) == next.end()) {
            next[to_find] = Trie();
            next[to_find].ch = to_find;
        }
        return &next[to_find];
    }
    int next_size() { return next.size(); }
    void insert(string word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            cur = cur->find(word[cursor]);
            if(cursor == word.size() - 1) cur->finish = true;
            ++cursor;
        }
    }
};

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

int builtout_popcount(int n) {
    int ret = 0;
    REP(i, 0, 32) if((n >> i) % 2 == 1) ++ret;
    return ret;
}

int builtout_popcount(ll n) {
    int ret = 0;
    REP(i, 0, 64) if((n >> i) % 2 == 1) ++ret;
    return ret;
}

vector<int> kmp(string &str) {
    vector<int> ret(str.size());
    int j = 0;
    for(int i=1; i<str.size(); i++) {
        while(j > 0 && str[i] != str[j]) j = ret[j-1];
        if(str[i] == str[j]) ret[i] = ++j;
    }
    return ret;
}

void FFT(vector<cpx> &vec, cpx w) {
    int n = vec.size();
    if(n == 1) return;
    vector<cpx> even, odd;
    for(int i=0; i<n; i++) {
        (i%2 ? odd : even).push_back(vec[i]);
    }
    FFT(even, w*w);
    FFT(odd, w*w);
    cpx wp(1, 0);
    for(int i=0; i<n/2; i++) {
        vec[i] = even[i] + wp*odd[i];
        vec[i+n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}

vector<int> multiply_polynomial(vector<cpx> &a, vector<cpx> &b) {
    vector<cpx> ret;
    int n = 1;
    int big = max(a.size(), b.size());
    while(n < big) n *= 2;
    n*= 2;
    a.resize(n), b.resize(n);
    cpx w(cos(2*PI/n), sin(2*PI/n));
    FFT(a, w);
    FFT(b, w);
    for(int i=0; i<n; i++) {
        ret.push_back(a[i] * b[i]);
    }
    FFT(ret, cpx(1,0)/w);
    vector<int> ans;
    for(int i=0; i<n; i++) {
        ret[i] /= cpx(n, 0);
        ret[i] = cpx(round(ret[i].real()), round(ret[i].imag()));
        ans.push_back(ret[i].real());
    }
    return ans;
}

// Definitions

// typedefs
typedef tuple<int, int, int> loc;

// Global Variables
const char BLANK = 'O', SWITCH = 'S', ZOMBIE = 'Z';
const char FRONT = 'F', TURN_LEFT = 'L', TURN_RIGHT = 'R';
const int DOWN = 0;
const int LEFT = 1;
const int UP = 2;
const int RIGHT = 3;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dy[] = {0, -1, 0, 1, 1, -1, 1, -1, 0};
// 현재 위치 + 상하좌우 + 대각선 벡터
int n;
string A;
vstr map_dasol;
bool light[20][20];

// functions
void turn_left(int &dir) { dir = (dir+3)%4; }
void turn_right(int &dir) { dir = (++dir)%4; }
void turn_back(int &dir) { dir = (dir+2)%4; }
bool check(pii p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n;
}
loc next(loc cur, int who) {
    int x, y, dir;
    tie(x, y, dir) = cur;
    x += dx[dir], y += dy[dir];
    if(!check({x, y})) {
        if(who == 0) return cur;
        return make_tuple(x-dx[dir], y-dy[dir], (dir+2)%4);
    }
    return make_tuple(x, y, dir);
}

int main() {
    FASTIO;
    cin >> n >> A;
    map_dasol = GET_N_STR(n);
    REP(i, 0, n) REP(j, 0, n) light[i][j] = false;
    vector<loc> zombies;
    REP(i, 0, n) {
        REP(j, 0, n) {
            if(map_dasol[i][j] == ZOMBIE) {
                map_dasol[i][j] = BLANK;
                zombies.push_back(make_tuple(i, j, DOWN));
            }
        }
    }
    pii cur = {0, 0};
    int dir = DOWN;
    bool alive = true;
    REP(i, 0, SIZE(A)) {
        if(!alive) break;
        // Action
        if(A[i] == FRONT) {
            auto forward = next(make_tuple(cur.first, cur.second, dir), 0);
            tie(cur.first, cur.second, dir) = forward;
            if(map_dasol[cur.first][cur.second] == SWITCH) {
                REP(j, 0, 9) {
                    pii next = {cur.first + dx[j], cur.second + dy[j]};
                    if(check(next)) light[next.first][next.second] = true;
                }
            }
        } else if(A[i] == TURN_LEFT) {
            turn_left(dir);
        } else if(A[i] == TURN_RIGHT) {
            turn_right(dir);
        }
        // Zombie move
        FOREACH(it, zombies) {
            if(!alive) break;
            int x, y, dir;
            tie(x, y, dir) = *it;
            if(cur.first == x && cur.second == y && !light[cur.first][cur.second] && map_dasol[cur.first][cur.second] != SWITCH) {
                alive = false;
            }
            *it = next(*it, 1);
            tie(x, y, dir) = *it;
            if(cur.first == x && cur.second == y && !light[cur.first][cur.second] && map_dasol[cur.first][cur.second] != SWITCH) {
                alive = false;
            }
            // cout << x << ' ' << y << ' ' << dir << '\n';
        }
    }
    if(alive) cout << "Phew...\n";
    else cout << "Aaaaaah!\n";
}