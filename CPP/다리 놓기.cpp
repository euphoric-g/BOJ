#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while(t-->0) {
        int n, m;
        std::cin >> n >> m;
        // 구하려는건 mCn
        // 분자 : m * (m-1) * (m-2) * ... * (m-n+1)
        // 분모 : n * (n-1) * (n-2) * ... * 1
        std::vector<int> up, down;
        for(int i=1; i<=n; i++) down.push_back(i);
        for(int i=m; i>=m-n+1; i--) up.push_back(i);
        for(int i=0; i<up.size(); i++) {
            for(int j=0; j<down.size(); j++) {
                if(down[j] != 1 && (up[i] % down[j] == 0)) {
                    up[i] /= down[j];
                    down[j] = 1;
                }
            }
        }
        long long ans = 1;
        for(int i=0; i<up.size(); i++) {
            ans *= up[i];
        }
        for(int j=0; j<down.size(); j++) {
            ans /= down[j];
        }
        std::cout << ans << "\n";
    }
}