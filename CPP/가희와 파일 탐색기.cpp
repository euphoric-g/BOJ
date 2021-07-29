#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

typedef struct {
    std::string fname, ext;
} file;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<file> files;
    std::unordered_map<std::string, int> extensions;
    for(int i=0; i<n; i++) {
        std::string fin;
        std::cin >> fin;
        auto sep = fin.find('.', 0);
        files.push_back(file{fin.substr(0, sep), fin.substr(sep+1, fin.size())});
    }
    for(int i=0; i<m; i++) {
        std::string ext;
        std::cin >> ext;
        extensions[ext] = 1;
    }
    std::sort(files.begin(), files.end(), [&extensions](const file &a, const file &b) -> bool {
        if(a.fname != b.fname) return a.fname < b.fname;
        if(extensions[a.ext] != extensions[b.ext]) return extensions[a.ext] > extensions[b.ext];
        return a.ext < b.ext;
    });
    for(const auto &f : files) {
        std::cout << f.fname << '.' << f.ext << '\n';
    }
    return 0;
}