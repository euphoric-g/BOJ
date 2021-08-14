#include <iostream>
#include <vector>

const int ROOT = 1;
const int NO_CHILD = -1;
const int LEFT = 0;
const int RIGHT = 1;

int tree[100001][2];
int moves = 0;

void pit(int node) {
    if(tree[node][LEFT] != NO_CHILD) {
        moves++;
        // std::cout << node << " to " << tree[node][LEFT] << "\n";
        pit(tree[node][LEFT]);
        // std::cout << tree[node][LEFT] << " to " << node << '\n';
        moves++;
    }
    if(tree[node][RIGHT] != NO_CHILD) {
        moves++;
        // std::cout << node << " to " << tree[node][RIGHT] << '\n';
        pit(tree[node][RIGHT]);
        moves++;
        // std::cout << tree[node][RIGHT] << " to " << node << '\n';
    }
}

int main() {
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        tree[a][LEFT] = b;
        tree[a][RIGHT] = c;
    }
    int cur = ROOT;
    while(tree[cur][RIGHT] != NO_CHILD) {
        moves--;
        cur = tree[cur][RIGHT];
    }
    pit(ROOT);
    std::cout << moves << '\n';
}