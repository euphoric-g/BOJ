#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    std::cin.ignore();
    while(t--) {
        std::string total;
        std::getline(std::cin, total);
        std::stringstream ss(total);
        std::string ret = "";
        while(!ss.eof()) {
            std::string word;
            ss >> word;
            std::reverse(word.begin(), word.end());
            ret += word;
            if(!ss.eof()) ret += ' ';
        }
        std::cout << ret << '\n';
    }
}