#include <iostream>
#include <vector>
#include <cmath>

bool *check;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    check = new bool[n+1];
    for(int i=0; i<=n; i++) check[i] = true;
    for(int i=2; i<=(int)sqrt(n); i++) {
        if(!check[i]) continue;
        for(int j=i*2; j<=n; j+=i) {
            check[j] = false;
        }
    }
    std::vector<int> sosu;
    for(int i=2; i<=n; i++) {
        if(check[i]) sosu.push_back(i);
    }
    int sosu_size = sosu.size();
    if(sosu_size == 0) {
        std::cout << 0 << '\n';
        return 0;
    }
    int left = 0, right = 0, sum = sosu[0];
    int count = 0;
    while(left <= right && left < sosu_size && right < sosu_size) {
        if(sum == n) {
            count++;
            sum += sosu[++right];
        } else if(sum > n) {
            sum -= sosu[left++];
        } else if(sum < n) {
            sum += sosu[++right];
        }
    }
    std::cout << count << '\n';
}