#include <iostream>
#include <string>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int sentence[n] = {0, };
    int cur = 1;
    std::string str;
    std::cin >> str;
    for(int i=0; i<n; i++) {
        sentence[i] = cur;
        if(str[i] == '.') cur++;
    }
    if(str.size() <= 25) {
        std::cout << str << '\n';
        return 0;
    } else {
        int sentence_num = sentence[11];
        int start = 11;
        int last = str.size()-11;
        bool same_sentence = true;
        while(start < last && same_sentence) {
            if(sentence[start] != sentence_num) same_sentence = false;
            start++;
        }
        if(same_sentence) {
            std::cout << str.substr(0, 11) + "..." + str.substr(str.size()-11, 11) + "\n";
        } else {
            std::cout << str.substr(0, 9) + "......" + str.substr(str.size()-10, 10) + "\n";
        }
    }
}