#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::string file, word;
    std::getline(std::cin, file);
    std::getline(std::cin, word);
    int cnt = 0;
    auto it = file.find(word, 0);
    while(it != std::string::npos) {
        cnt++;
        it = file.find(word, it+word.size());
    }
    std::cout << cnt << '\n';
}