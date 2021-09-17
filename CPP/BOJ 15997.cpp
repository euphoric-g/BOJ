#include <bits/stdc++.h>

/*
    C++ Template by LJH

    Last Update : 21/09/16

    Macros
    FASTIO, MAX, MIN, ALL, UNIQUE, UNIQUE_ERASE, FOREACH, REP, POPCOUNT(int, ll), BINSEARCH,
    LOWERBOUND, UPPERBOUND, SORT, SORT_REV, MAX_ELEMENT, MIN_ELEMENT, SWAP, DO_PERMUTATION,
    DO_PREV_PERMUTATION, GCD, LCM, VINT(vector<int> with n inits), PRINT
    
    Data Structures
    Segment Tree(for max histogram area, max value), Priority_queue(with various comp func)

    Algorithm

    KMP, Trie, Segment Tree (for max histogram area, max value),
    FFT(Fast Fourier Transform), TSP(Traveling Salesman Problem),
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

vector<string> GET_N_STRING(int n) {
    vector<string> ret = VSTR(n);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}

const double PI = acos(-1);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cpx;

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

int main() {
    FASTIO;
    const int WIN = 0, DRAW = 1, LOSE = 2;
    auto countries = GET_N_STRING(4);
    unordered_map<string, int> name_to_index;
    double table[4][4][3];
    int vs[6][2] = { {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3} };
    REP(i, 0, 4) name_to_index[countries[i]] = i;
    REP(i, 0, 6) {
        string A, B;
        double w, d, l;
        cin >> A >> B >> w >> d >> l;
        int a = name_to_index[A], b = name_to_index[B];
        table[a][b][WIN] = w, table[a][b][DRAW] = d, table[a][b][LOSE] = l;
        table[b][a][WIN] = l, table[b][a][DRAW] = d, table[b][a][LOSE] = w;
    }
    vector<double> final_prob(4, 0);
    REP(i, 0, 729) {
        int result[6];
        vector<int> pts = VINT(4, 0);
        double prob = 1.0;
        REP(j, 0, 6) {
            result[j] = (i / (int)pow(3, j)) % 3;
            switch(result[j]) {
                case 0:
                pts[vs[j][0]] += 3;
                break;
                case 1:
                ++pts[vs[j][0]], ++pts[vs[j][1]];
                break;
                case 2:
                pts[vs[j][1]] += 3;
                break;
            }
            prob *= table[vs[j][0]][vs[j][1]][result[j]];
        }
        auto copy = pts;
        SORT(copy);
        UNIQUE_ERASE(copy);
        SORT_REV(copy);
        if(copy.size() == 1) {
            REP(j, 0, 4) final_prob[j] += prob / 2;
            continue;
        }
        vector<int> first, second;
        REP(j, 0, 4) {
            if(pts[j] == copy[0]) first.push_back(j);
            if(pts[j] == copy[1]) second.push_back(j);
        }
        if(first.size() == 3) {
            final_prob[first[0]] += prob * 2 / 3;
            final_prob[first[1]] += prob * 2 / 3;
            final_prob[first[2]] += prob * 2 / 3;
            continue;
        }
        if(first.size() == 2) {
            final_prob[first[0]] += prob;
            final_prob[first[1]] += prob;
            continue;
        }
        if(first.size() == 1) final_prob[first[0]] += prob;
        if(second.size() == 3) {
            final_prob[second[0]] += prob / 3;
            final_prob[second[1]] += prob / 3;
            final_prob[second[2]] += prob / 3;
            continue;
        }
        if(second.size() == 2) {
            final_prob[second[0]] += prob / 2;
            final_prob[second[1]] += prob / 2;
            continue;
        }
        if(second.size() == 1) final_prob[second[0]] += prob;
    }
    cout << fixed << setprecision(9);
    PRINTLN(final_prob);
}