#include <iostream>

using namespace std;

long long n, k, moves = 0;
int tower[3] = {0,};
pair<int, int> find_flag = {-1, -1};
void move(int from, int to, int temp, int level) {
    if(find_flag != make_pair(-1, -1)) return;
    if(level == 1) {
        --tower[from], ++tower[to];
        if(++moves == k) find_flag = {from, to};
        return;
    }
    if(moves - 1 + (1LL << (level - 1)) < k) {
        moves += (1LL << (level - 1)) - 1;
        tower[from] -= level - 1;
        tower[temp] += level - 1;
    } else move(from, temp, to, level - 1);
    move(from, to, temp, 1);
    if(moves - 1 + (1LL << (level - 1)) < k) {
        moves += (1LL << (level - 1)) - 1;
        tower[temp] -= level - 1;
        tower[to] += level - 1;
    } else move(temp, to, from, level - 1);
}

int main() {
    cin >> n >> k;
    tower[0] = n;
    move(0, 2, 1, n);
    cout << find_flag.first+1 << ' ' << find_flag.second+1 << '\n';
}