#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string code;
    std::cin >> code;
    std::string ans = "";
    for(const auto &ch : code) {
        if(ch != 'J' && ch != 'A' && ch != 'V') {
            ans += ch;
        }
    }
    if(ans == "") {
        ans = "nojava";
    }
    std::cout << ans << '\n';
    return 0;
}