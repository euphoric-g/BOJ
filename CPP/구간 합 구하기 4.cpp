#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    long long *arr, *sum;
    arr = new long long[n];
    sum = new long long[n];
    for(int i=0; i<n; i++) {
        arr[i] = 0;
        sum[i] = 0;
    }
    for(int i=0; i<n; i++) {
        std::cin >> arr[i];
        if(i!=0) sum[i] = sum[i-1] + arr[i];
    }
    for(int i=0; i<m; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << sum[b-1] - sum[a-1] + arr[a-1] << '\n';
    }
    delete[] arr, sum;
    return 0;
}