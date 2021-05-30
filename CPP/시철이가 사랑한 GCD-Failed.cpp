#include <iostream>
#include <vector>
#include <cmath>

/*
    arr = 10 5 15 9 20 16 80 30

            1
        1       2
      5   3   4   10
     * * * * * * * *
*/
int gcd(int a, int b) {
    if(a == -1) return b;
    if(b == -1 || b == 0) return a;
    if(b == 1) return 1;
    return gcd(b, a%b);
}

class SegTree {
    public:
    int n;
    int tree_height, tree_size;
    int beauty = 0;
    std::vector<int> arr;
    std::vector<int> tree;
    int init(int start, int end, int node) {
        if(start == end) return tree[node] = arr[start];
        int mid = (start + end)/2;
        return tree[node] = gcd(init(start, mid, node*2), init(mid+1, end, node*2+1));
    }
    int get(int start, int end, int left, int right, int node) {
        if(start > right || end < left) return -1;
        if(start >= left && end <= right) return tree[node];
        int mid = (start + end)/2;
        return gcd(get(start, mid, left, right, node*2), get(mid+1, end, left, right, node*2+1));
    }
    void show() {
        for(int i=1; i<tree_size; i++) {
            std::cout << tree[i] << ' ';
            if( i == 1 || i == 3 || i == 7 || i == 15 || i == 31 || i == 63 ) std::cout << '\n';
        }
    }
    SegTree() {
        std::cin >> n;
        for(int i=0; i<n; i++) {
            int elem;
            std::cin >> elem;
            arr.push_back(elem);
        }
        tree_height = (int)ceil(log2(n));
        tree_size = 1 << (tree_height + 1);
        tree = std::vector<int>(tree_size, 0);
        init(0, n-1, 1);
    }
    void bruteforce() {
        if(n == 1) {
            beauty = arr[0];
            return;
        }
        for(int i=0; i<(1 << tree_height+1); i++) {
            int num = i;
            int gcd_sum = 0;
            int left = 0, right = n-1;
            while(left < right) {
                // 하나 남을 때까지
                int select = num % 2;
                num /= 2;
                int counts = (right - left + 1)/2;
                if(select == 0) {
                    // 왼쪽에서 counts개 선택
                    gcd_sum += get(0, n-1, left, left+counts-1, 1);
                    left += counts;
                } else {
                    // 오른쪽에서 counts개 선택
                    gcd_sum += get(0, n-1, right-counts+1, right, 1);
                    right -= counts;
                }
            }
            if(left == right) gcd_sum += get(0, n-1, left, right, 1);
            beauty = std::max(beauty, gcd_sum);
        }
    }
};

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);
    SegTree st = SegTree();
    st.bruteforce();
    std::cout << st.beauty << '\n';
    return 0;
}