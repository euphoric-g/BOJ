#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int init_stree(std::vector<int> &tree, std::vector<int> &arr, int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = std::min(init_stree(tree, arr, start, mid, node *2), init_stree(tree, arr, mid+1, end, node *2 + 1));
}

int find_min(std::vector<int> &tree, std::vector<int> &arr, int start, int end, int left, int right, int node) {
    if(end < left || start > right) return INT32_MAX;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return std::min(find_min(tree, arr, start, mid, left, right, node * 2), find_min(tree, arr, mid+1, end, left, right, node*2 + 1));
}

int main() {
    std::cin.tie(0);
    std::iostream::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> arr;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        std::cin >> arr[i];
    }
    std::vector<int> tree;
    int tree_height = (int)ceil(log2(n));
    int tree_size = 1 << (tree_height + 1);
    tree.resize(tree_size);
    init_stree(tree, arr, 0, n-1, 1);
    for(int i=0; i<m; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << find_min(tree, arr, 0, n-1, a-1, b-1, 1) << "\n";
    }
}