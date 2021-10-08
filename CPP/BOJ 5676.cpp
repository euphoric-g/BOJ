#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

const std::string str[3] = {"-", "0", "+"};

int convert(int a) {
    if(a > 0) return 1;
    if(a < 0) return -1;
    return 0;
}

int init(int *tree, int *arr, int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = init(tree, arr, start, mid, node*2) * init(tree, arr, mid+1, end, node*2+1);
}

int update(int *tree, int start, int end, int node, int index, int dif) {
    if(index < start || end < index) return tree[node];
    if(start == end && start == index) return tree[node] = dif;
    else {
        int mid = (start + end)/2;
        return tree[node] = update(tree, start, mid, node*2, index, dif) * update(tree, mid+1, end, node*2+1, index, dif);
    }
}

int answer(int *tree, int start, int end, int left, int right, int node) {
    if(end < left || start > right) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return answer(tree, start, mid, left, right, node*2) * answer(tree, mid+1, end, left, right, node*2+1);
}

void show(int *tree, int n) {
    int cursor = 1;
    int h = (int)ceil(log2(n));
    for(int i=0; i<=h; i++) {
        for(int j=0; j<(1 << i); j++) {
            std::cout << tree[cursor++] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(0);
    std::iostream::sync_with_stdio(0);
    bool first = true;
    while(1) {
        int n, k;
        if(!(std::cin >> n >> k)) break;
        int *arr = new int[n];
        for(int i=0; i<n; i++) {
            std::cin >> arr[i];
            arr[i] = convert(arr[i]);
        }
        int *tree = new int[1 << ((int)ceil(log2(n)) + 1)];
        std::string results = "";
        init(tree, arr, 0, n-1, 1);
        for(int i=0; i<k; i++) {
            char op;
            int a, b;
            std::cin >> op >> a >> b;
            if(op == 'C') {
                update(tree, 0, n-1, 1, a-1, convert(b));
                arr[a-1] = convert(b);
            } else {
                results += str[answer(tree, 0, n-1, a-1, b-1, 1)+1];
            }
        }
        std::cout << results << "\n";
        delete[] arr;
        delete[] tree;
    }
    return 0;
}