#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        std::cout << s1 << " & " << s2 << " are ";
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        if(s1 == s2) {
            std::cout << "anagrams.\n";
        } else std::cout << "NOT anagrams.\n";
    }
}