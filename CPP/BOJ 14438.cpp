#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

class SegTree {
    public:
    std::vector<int> arr;
    std::vector<int> tree;
    int arrlen;
    int tree_height;
    int tree_size;
    SegTree() {
        std::cin >> arrlen;
        for(int i=0; i<arrlen; i++) {
            int temp;
            std::cin >> temp;
            arr.push_back(temp);
        }
        tree_height = (int)ceil(log2(arrlen));
        tree_size = 1 << (tree_height + 1);
        tree = std::vector<int>(tree_size, 0);
        init(0, arrlen-1, 1);
    }
    int init(int start, int end, int node) {
        if(start == end) return tree[node] = arr[start];
        int mid = (start + end)/2;
        return tree[node] = std::min(init(start, mid, node*2), init(mid+1, end, node*2+1));
    }
    int update(int start, int end, int node, int index, int num) {
        if(index < start || index > end) return tree[node];
        if(start != end) {
            int mid = (start + end)/2;
            return tree[node] = std::min(update(start, mid, node*2, index, num), update(mid+1, end, node*2+1, index, num));
        } else {
            return tree[node] = num;
        }
    }
    int get_min(int start, int end, int left, int right, int node) {
        if(end < left || right < start) return INT32_MAX;
        if(left <= start && end <= right) return tree[node];
        int mid = (start + end)/2;
        return std::min(get_min(start, mid, left, right, node*2), get_min(mid+1, end, left, right, node*2+1));
    }
    void query(int op, int a, int b) {
        if(op == 1) {
            // change
            update(0, arrlen-1, 1, a-1, b);
        }
        if(op == 2) {
            // output
            std::cout << get_min(0, arrlen-1, a-1, b-1, 1) << "\n";
        }
    }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    SegTree st = SegTree();
    int m;
    std::cin >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        st.query(a, b, c);
    }
    return 0;
}