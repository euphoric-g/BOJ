#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;
    for(int i=0; i<word.size(); i++) {
        word[i] -= 3;
        if(word[i] < 'A') word[i] += 26;
    }
    std::cout << word << '\n';
}