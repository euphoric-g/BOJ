#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

class SegTree {
    public:
    std::vector<ll> tree;
    std::vector<ll> arr;
    int size, updates, sums;
    SegTree() {
        std::cin >> size >> updates >> sums;
        int querys = updates + sums;
        for(int i=0; i<size; i++) {
            int in;
            std::cin >> in;
            arr.push_back(in);
        }
        int tree_height = (int)ceil(log2(size));
        int tree_size = 1 << (tree_height + 1);
        tree = std::vector<ll>(tree_size, 0);
        init_SegTree(1, 0, size-1);
        for(int i=0; i<querys; i++) {
            ll a, b, c;
            std::cin >> a >> b >> c;
            query(a, b, c);
        }
    }
    void show() {
        for(int i=0; i<tree.size(); i++) {
            std::cout << tree[i] << " ";
        }
        std::cout << "\n";
    }
    ll init_SegTree(int node, int start, int end) {
        if(start == end) {
            return tree[node] = arr[start];
        }
        int mid = (start + end) / 2;
        return tree[node] = init_SegTree(node * 2, start, mid) + init_SegTree(node * 2 + 1, mid + 1, end);
    }
    void update(int node, int start, int end, int index, ll dif) {
        if(index < start || index > end) return;
        int mid = (start + end) / 2;
        tree[node] += dif;
        if(start != end) {
            update(node * 2, start, mid, index, dif);
            update(node * 2 + 1, mid + 1, end, index, dif);
        }
    }
    ll sum(int node, int start, int end, int left, int right) {
        if(start > right || end < left) return 0;
        if(start >= left && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
    }
    void query(ll a, ll b, ll c) {
        if(a == 1) {
            // change
            update(1, 0, size-1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        } else if(a == 2) {
            // sum
            std::cout << sum(1, 0, size-1, b-1, c-1) << "\n";
        }
    }
};

int main() {
    std::iostream::sync_with_stdio(0);
    std::cin.tie(0);
    SegTree st = SegTree();
    return 0;
}