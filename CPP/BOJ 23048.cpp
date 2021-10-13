#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, color_cnt = 1;
    cin >> n;
    vector<int> arr(n+1, 0);
    arr[1] = 1;
    if(n >= 2) ++color_cnt;
    for(int i=2; i<=n; i+=2) {
        arr[i] = color_cnt;
    }
    for(int i=3; i<=n; i+=2) {
        if(arr[i]) continue;
        ++color_cnt;
        for(int j=i; j<=n; j+=i) if(!arr[j]) arr[j] = color_cnt;
    }
    cout << color_cnt << '\n';
    for(int i=1; i<=n; i++) cout << arr[i] << ' ';
    cout << '\n';
}