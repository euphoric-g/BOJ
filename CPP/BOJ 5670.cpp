#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

#include <fstream>

// #define DEBUG
// #define FILE_DEBUG
#define FASTIO

class Trie {
    public:
    bool finish;
    char cur_ch;
    bool is_root;
    std::map<char, Trie> next;
    Trie() {}
    Trie(char c) { cur_ch = c; is_root = false; }
    void insert(std::string word) {
        if(word.size() == 0) {
            finish = true;
            return;
        }
        if(next.find(word[0]) == next.end()) {
            next[word[0]] = Trie(word[0]);
        }
        next[word[0]].insert(word.substr(1, word.size()));
    }
    void print(int depth) {
        if(!is_root) std::cout << std::string(depth, ' ') << cur_ch << '\n';
        for(auto &item : next) item.second.print(depth+1);
    }
    int find(std::string word) {
        if(word.size() == 0 && finish) return 0;
        // 남은 단어가 없고 해당 위치에서 끝날때 : 탐색 끝
        if(is_root) {
#ifdef DEBUG
            std::cout << "press " << word[0] << '\n';
#endif
            return 1+next[word[0]].find(word.substr(1, word.size()));
        }
        // 시작 위치일 때 : 첫 글자 입력
        if(!finish && next.size() == 1) {
#ifdef DEBUG
            std::cout << "auto " << word[0] << '\n';
#endif
            return next[word[0]].find(word.substr(1, word.size()));
        }
        // 현재 위치에서 끝나는 단어가 없고 다음 글자가 한 종류일 때 : 통과
#ifdef DEBUG
        std::cout << "press " << word[0] << '\n';
#endif
        return 1+next[word[0]].find(word.substr(1, word.size()));
        // 이외의 경우에는 다음 글자를 입력한다.
    }
};

int main() {
#ifdef FASTIO
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
#endif
#ifdef FILE_DEBUG
    std::ifstream fin;
    fin.open("input.txt", std::ios::in);
    auto &is = fin;
#endif
#ifndef FILE_DEBUG
    auto &is = std::cin;
#endif
    int n;
    while(is >> n) {
        Trie t = Trie();
        t.is_root = true;
        std::vector<std::string> dict;
        for(int i=0; i<n; i++) {
            std::string str;
            is >> str;
            dict.push_back(str);
            t.insert(str);
        }
#ifdef DEBUG
        t.print(-1);
#endif
        double sum = 0.0;
        for(const auto &str : dict) {
            int result = t.find(str);
#ifdef DEBUG
            std::cout << "find(" << str << ") = " << result << '\n';
#endif
            sum += result;
        }
        std::cout << std::fixed << std::setprecision(2) << sum/dict.size() << '\n';
    }
    return 0;
}