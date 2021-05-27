#include <iostream>
#include <string>

int difference(std::string &a, std::string &b, int ind) {
    int cnt = 0;
    int size = a.size();
    for(int i=0; i<size; i++) {
        if(a[i] != b[i+ind]) cnt++;
    }
    return cnt;
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int n = s2.size() - s1.size();
    int min_diff = s2.size();
    for(int i=0; i<=n; i++) {
        min_diff = std::min(min_diff, difference(s1, s2, i));
    }
    std::cout << min_diff << '\n';
    return 0;
}