#include <iostream>
#include <vector>
#include <map>

int gcd(int a, int b) {
    if(b == 0) return a;
    if(b == 1) return 1;
    return gcd(b, a%b);
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<int> arr(n, 0);
    for(int i=0; i<n; i++) std::cin >> arr[i];
    bool all_equal = true;
    int temp = arr[0];
    for(int i=0; i<n; i++) if(temp != arr[i]) all_equal = false;
    if(n == 1) {
        std::cout << "A\n";
        return 0;
    } else if(n == 2) {
        if(arr[0] == arr[1]) {
            std::cout << arr[0] << '\n';
            return 0;
        } else {
            std::cout << "A\n";
            return 0;
        }
    } else if(all_equal) {
        std::cout << temp << '\n';
        return 0;
    }
    all_equal = true;
    temp = arr[1];
    for(int i=1; i<n; i++) if(temp != arr[i]) all_equal = false;
    if(all_equal) {
        std::cout << temp << '\n';
        return 0;
    }
    std::map<std::pair<int, int>, int> dict;
    std::vector<std::pair<int, int>> vec;
    std::pair<int, int> get;
    int cnt = 0;
    for(int i=0; i<n-2; i++) {
        vec.push_back({arr[i+1]-arr[i], arr[i+2]-arr[i+1]});
    }
    for(const auto &item : vec) {
        // 1,0 0,0
        int gcd_tmp = gcd(item.first, item.second);
        std::pair<int, int> cur;
        if(gcd_tmp != 0) cur = {item.first / gcd_tmp, item.second / gcd_tmp };
        else cur = {0, cur.second};
        if(cur.first == -1) cur = {1, -cur.second};
        if(++dict[cur] == n-2 && cur.first == 1) {
            get = cur;
            cnt++;
        }
    }
    if(cnt == 0) {
        std::cout << "B\n";
        return 0;
    } else if(cnt > 1) {
        std::cout << "A\n";
        return 0;
    } else {
        int b = arr[1] - get.second * arr[0];
        std::cout << arr[n-1] * get.second + b << '\n';
        return 0;
    }
}
/*
a+b = 2
2a+b = 2
2a+b = 2
a=0 b=2


3 5 5 5

*/