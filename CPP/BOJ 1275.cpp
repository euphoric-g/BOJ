#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;

ll init_seg_tree(std::vector<ll> &arr, std::vector<ll> &tree, int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init_seg_tree(arr, tree, node * 2, start, mid) + init_seg_tree(arr, tree, node * 2 + 1, mid+1, end);
}

void update_seg_tree(std::vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if(!(start <= index && index <= end)) return;
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end) / 2;
        update_seg_tree(tree, node *2, start, mid, index, diff);
        update_seg_tree(tree, node *2 + 1, mid + 1, end, index, diff);
    }
}

ll sum(std::vector<ll> &tree, int node, int start, int end, int left, int right) {
    if(end < left || start > right) return 0;
    if(start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(tree, node*2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}

int main() {
    std::iostream::sync_with_stdio(0);
    std::cin.tie(0);
    ll n, q;
    std::vector<ll> arr;
    std::cin >> n >> q;
    int tree_height = (int)ceil(log2(n));
    ll tree_size = 1 << (tree_height + 1);
    std::vector<ll> tree = std::vector<ll>(tree_size, 0);
    for(int i=0; i<n; i++) {
        ll in;
        std::cin >> in;
        arr.push_back(in);
    }
    init_seg_tree(arr, tree, 1, 0, n-1);
    for(int i=0; i<q; i++) {
        ll x, y, a, b;
        std::cin >> x >> y >> a >> b;
        if(x <= y) std::cout << sum(tree, 1, 0, n-1, x-1, y-1) << "\n";
        else std::cout << sum(tree, 1, 0, n-1, y-1, x-1) << "\n";
        update_seg_tree(tree, 1, 0, n-1, a-1, b-arr[a-1]);
        arr[a-1] = b;
    }
    return 0;
}