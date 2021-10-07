#include <bits/stdc++.h>

/*
    C++ Template by LJH
    Last Update : 21/09/28
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
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<pis> vpis;
typedef vector<pss> vpss;
typedef complex<double> cpx;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, string> umis;

void FAST_IO() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
}
// function : 입출력 속도 향상

class Trie {
    /*
    필요한 곳에서 Trie root = Trie(0); 으로 선언 후
    필요한 단어들을 root에 삽입
    적절한 후처리는 구현 필요
    */
    public:
    bool is_root = false, finish = false;
    map<char, Trie*> next;
    Trie() {is_root = false;}
    Trie(int i) {is_root = true;}
    bool exist(char to_find) {
        return next.find(to_find) != next.end();
    }
    Trie *find(char to_find) {
        if(next.find(to_find) == next.end()) {
            next[to_find] = new Trie();
        }
        return next[to_find];
    }
    int next_size() { return next.size(); }
    void insert(string &word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            cur = cur->find(word[cursor]);
            if(cursor == word.size() - 1) cur->finish = true;
            ++cursor;
        }
    }
    Trie *rtn_trie_ptr(string &word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            if(!cur->exist(word[cursor])) return nullptr;
            cur = cur->next[word[cursor++]];
        }
        return cur;
    }
};
// Data Structure : Trie

// Definitions

// typedefs

// Global Variables
const int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
// functions

int main() {
    FASTIO;
    int w;
    cin >> w;
    Trie dict = Trie(0);
    REP(i, 0, w) {
        string in;
        cin >> in;
        dict.insert(in);
    }
    int b;
    cin >> b;
    while(b--) {
        vstr bd(4);
        REP(i, 0, 4) cin >> bd[i];
        string board = bd[0] + bd[1] + bd[2] + bd[3];
        unordered_map<string, int> words_found;
        int local_score = 0;
        string longest_word = "";
        queue<pair<pii, string>> q; // {{visited, current_pos}, temp_string}
        REP(i, 0, 16) q.push({pii(1 << i, i), board.substr(i, 1)});
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            auto ptr = dict.rtn_trie_ptr(cur.second);
            if((ptr != nullptr) && (ptr->finish) && (words_found[cur.second] == 0)) {
                words_found[cur.second]++;
                local_score += score[cur.second.size()];
                if(cur.second.size() > longest_word.size()) {
                    longest_word = cur.second;
                } else if(cur.second.size() == longest_word.size() && cur.second < longest_word) {
                    longest_word = cur.second;
                }
            }
            if(cur.second.size() >= 8) continue;
            if(ptr == nullptr) continue;
            REP(i, 0, 8) {
                pii next_pii = {cur.first.second/4 + dx[i], cur.first.second%4 + dy[i]};
                if(next_pii.first < 0 || next_pii.first >= 4 || next_pii.second < 0 || next_pii.second >= 4) continue;
                int next = next_pii.first * 4 + next_pii.second;
                string next_str = cur.second + board[next];
                if((!(cur.first.first & (1 << next))) && ptr->exist(board[next])) {
                    q.push({pii(cur.first.first | (1 << next), next), next_str});
                }
            }
        }
        cout << local_score << ' ' << longest_word << ' ' << words_found.size() << '\n';
    }
}