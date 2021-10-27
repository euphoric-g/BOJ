#include <iostream>
#include <string>

using namespace std;

pair<int, int> diff(string &ref_op) {
    if(ref_op == "R") return {0, 1};
    if(ref_op == "L") return {0, -1};
    if(ref_op == "B") return {-1, 0};
    if(ref_op == "T") return {1, 0};
    if(ref_op == "RT") return {1, 1};
    if(ref_op == "LT") return {1, -1};
    if(ref_op == "RB") return {-1, 1};
    if(ref_op == "LB") return {-1, -1};
    return {0, 0};
}
auto pos_check = [](pair<int, int> &cur) -> bool {
    return cur.first >= 0 && cur.first < 8 && cur.second >= 0 && cur.second < 8;
};
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}
bool operator==(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first && a.second == b.second;
}

int main() {
    string k_init, d_init;
    int n;
    cin >> k_init >> d_init >> n;
    pair<int, int> king_loc = {k_init[1] - '1', k_init[0] - 'A'};
    pair<int, int> dol_loc = {d_init[1] - '1', d_init[0] - 'A'};
    while(n--) {
        string op;
        cin >> op;
        auto mov = diff(op);
        auto next_king_loc = king_loc + mov;
        pair<int, int> next_dol_loc = dol_loc;
        if(next_king_loc == dol_loc) next_dol_loc = dol_loc + mov;
        if(pos_check(next_king_loc) && pos_check(next_dol_loc)) {
            king_loc = next_king_loc;
            dol_loc = next_dol_loc;
        }
    }
    cout << (char)(king_loc.second + 'A') << king_loc.first+1 << '\n';
    cout << (char)(dol_loc.second + 'A') << dol_loc.first+1 << '\n';
}