#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define L 0
#define O 1
#define V 2
#define E 3

std::vector<int> convert(std::string str) {
    std::vector<int> ret = std::vector<int>(4, 0);
    int strlen = str.size();
    for(int i=0; i<strlen; i++) {
        switch(str[i]) {
            case 'L':
            ret[L]++;
            break;
            case 'O':
            ret[O]++;
            break;
            case 'V':
            ret[V]++;
            break;
            case 'E':
            ret[E]++;
            break;
        }
    }
    return ret;
}

int calc(std::vector<int> name1, std::vector<int> name2) {
    int sum[4];
    for(int i=0; i<4; i++) {
        sum[i] = name1[i] + name2[i];
    }
    return ((sum[L]+sum[O])*(sum[L]+sum[V])*(sum[L]+sum[E])*(sum[O]+sum[V])*(sum[O]+sum[E])*(sum[V]+sum[E])) % 100;
}

bool compare(const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}
int main() {
    int n;
    std::string name_oh;
    std::cin >> name_oh;
    std::vector<int> convert_oh = convert(name_oh);
    std::cin >> n;
    std::vector<std::pair<int, std::string>> ans;
    for(int i=0; i<n; i++) {
        std::string name_in;
        std::cin >> name_in;
        ans.push_back(std::pair<int, std::string>(calc(convert_oh, convert(name_in)), name_in));
    }
    std::sort(ans.begin(), ans.end(), compare);
    std::cout << ans.front().second << std::endl;
}