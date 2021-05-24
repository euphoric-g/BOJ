#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define PLUS 1
#define ZERO 0
#define MINUS -1

int convert(int val) {
    if(val > 0) return PLUS;
    if(val < 0) return MINUS;
    return ZERO;
}

int init(std::vector<int> &tree, std::vector<int> &arr, int start, int end, int node) {
    if(start == end) return tree[node] = convert(arr[start]);
    int mid = (start + end)/2;
    return tree[node] = convert(init(tree, arr, start, mid, node *2)) * convert(init(tree, arr, mid+1, end, node *2 +1));
}

int update(std::vector<int> &tree, int start, int end, int node, int index, int dif) {
    if(index < start || index > end) return tree[node];
    int mid = (start + end)/2;
    if(start != end) {
        return tree[node] = update(tree, start, mid, node *2, index, dif) * update(tree, mid+1, end, node *2 + 1, index, dif);
    } else {
        return tree[node] = dif;
    }
}

int result(std::vector<int> &tree, int start, int end, int left, int right, int node) {
    if(end < left || right < start) return PLUS;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return result(tree, start, mid, left, right, node*2) * result(tree, mid+1, end, left, right, node *2 + 1);
}

void show(std::vector<int> &tree) {
    for(int i=1; i<tree.size(); i++) {
        std::cout << tree[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(0);
    std::iostream::sync_with_stdio(0);
    auto &is = std::cin;
    while(1) {
    int n, k;
    if(is >> n >> k) break;
    std::vector<int> arr;
    std::vector<int> tree;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        is >> arr[i];
    }
    int tree_h = (int)ceil(log2(n));
    int tree_size = 1 << (tree_h + 1);
    tree.resize(tree_size);
    init(tree, arr, 0, n-1, 1);
    for(int i=0; i<k; i++) {
        char op;
        int a, b;
        is >> op >> a >> b;
        if(op == 'C') {
            arr[a-1] = convert(b);
            update(tree, 0, n-1, 1, a-1, arr[a-1]);
        } else {
            int ans = result(tree, 0, n-1, a-1, b-1, 1);
            if(ans > 0) std::cout << "+";
            else if(ans < 0) std::cout << "-";
            else std::cout << "0";
        }
    }
    std::cout << "\n";
    }
    return 0;
}