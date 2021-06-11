#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
// #include <fstream>

#define ROOT 0

// #define DEBUG

class Trie {
    public:
    bool is_root = false;
    bool finish = false;
    char ch;
    std::map<char, Trie> next;
    Trie() { is_root = false; }
    Trie(int i) { is_root = true; }
    Trie *find(char to_find) {
        if(next.find(to_find) == next.end()) {
            next[to_find] = Trie();
            next[to_find].ch = to_find;
        }
        return &next[to_find];
    }
    int next_size() {
        return next.size();
    }
    void insert(std::string word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            cur = cur->find(word[cursor]);
            if(cursor == word.size() - 1) cur->finish = true;
            cursor++;
        }
    }
    void show(int depth) {
        if(!is_root) std::cout << std::string(depth, ' ') << ch << '\n';
        for(auto &item : next) {
            item.second.show(depth+1);
        }
    }
    int explore(std::string str) {
        int strcur = 0;
        int wordlen = str.size();
        int clicks = 0;
        Trie *cur = this;
        while(strcur < wordlen) {
            /*
            현재 위치가 root인 경우 -> 입력
            탐색 중인 단어가 현재 위치에서 끝날때 -> 통과 후 탐색 종료
            현재 위치에서 끝나는 단어가 없으며 다음 글자가 하나만 있으면 -> 자동 입력
            현재 위치에서 끝나는 단어가 있으면 -> 입력
            현재 위치에서 끝나는 단어가 없지만 다음 글자가 여러개라면 -> 입력
            */
            if(cur->is_root) {
                // 첫 글자는 입력
                // std::cout << "[ROOT] click " << str[strcur] << '\n';
                cur = &cur->next[str[strcur++]];
                clicks++;
            } else if(cur->finish) {
                // 해당 위치에서 끝나는 문자가 있으면 다음 문자 입력
                //std::cout << "[FINISH=TRUE] click " << str[strcur] << '\n';
                cur = &cur->next[str[strcur++]];
                clicks++;
            } else if(!cur->finish && cur->next_size() > 1) {
                // 해당 위치에서 끝나는 문자는 없지만 다음 글자가 2개 이상인 경우 다음 문자 입력 
                // std::cout << "[TWO_OR_MORE] click " << str[strcur] << '\n';
                cur = &cur->next[str[strcur++]];
                clicks++;
            } else if(!cur->finish && cur->next_size() == 1) {
                // std::cout << "[AUTO] " << str[strcur] << '\n';
                // 해당 위치에서 끝나는 문자가 없고 다음 글자가 1개인 경우 자동 입력
                cur = &cur->next[str[strcur++]];
            } else if(strcur == wordlen-1 && cur->finish) {
                // 해당 글자가 단어의 마지막이면 통과 후 탐색 종료
                // std::cout << "[LAST] passed\n";
                return clicks;
            } 
        }
        return clicks;
    }
};

int main() {
    /*
    std::ifstream fin;
    fin.open("input.txt", std::ios::in);
    auto &is = fin;
    */
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    auto &is = std::cin;
    int n;
    while(is >> n) {
        Trie dict = Trie(ROOT);
        std::vector<std::string> strlist;
        for(int i=0; i<n; i++) {
            std::string word;
            is >> word;
            dict.insert(word);
            strlist.push_back(word);
        }
        // dict.show(-1);
        double clicks = 0.0;
        for(const auto &str : strlist) {
            clicks += dict.explore(str);
        }
        std::cout << std::fixed << std::setprecision(2) << clicks/n << '\n';
    }
    return 0;
}