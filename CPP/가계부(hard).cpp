#include <cstdio>
#include <vector>
#include <cmath>

typedef long long ll;

ll *arr;
ll *tree;

ll init(ll *tree, ll *arr, int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = init(tree, arr, start, mid, node * 2) + init(tree, arr, mid+1, end, node * 2 + 1);
}

void update(ll *tree, ll *arr, int start, int end, int node, int index, ll diff) {
    if(index < start || end < index) return;
    tree[node] += diff;
    if(start != end) {
        int mid = (start + end)/2;
        update(tree, arr, start, mid, node*2, index, diff);
        update(tree, arr, mid+1, end, node*2+1, index, diff);
    }
}

ll sum(ll *tree, ll *arr, int start, int end, int left, int right, int node) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return sum(tree, arr, start, mid, left, right, node*2) + sum(tree, arr, mid+1,end, left, right, node*2+1);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    arr = new ll[n];
    int tree_height = (int)ceil(log2(n));
    int tree_size = 1 << (tree_height + 1);
    tree = new ll[tree_size];
    init(tree, arr, 0, n-1, 1);
    for(int i=0; i<q; i++) {
        int op, p, x;
        scanf("%d %d %d", &op, &p, &x);
        if(op == 1) {
            // update p x
            update(tree, arr, 0, n-1, 1, p-1, x);
        } else if(op == 2) {
            // show p x
            printf("%lld\n", sum(tree, arr, 0, n-1, p-1, x-1, 1));
        }
    }
    delete[] tree;
    delete[] arr;
    return 0;
}