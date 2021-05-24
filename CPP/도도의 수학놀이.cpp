#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::string rev[10] = { "0", "1", "2", "0", "0", "5", "9", "0", "8", "6" };

std::string reverse_str(std::string &str) {
    std::string ret = "";
    int strlen = str.size();
    for(int i=strlen-1; i>=0; i--) {
        if(isdigit(str[i])) ret += rev[str[i]-'0'];
    }
    return ret;
}

bool compare_str(std::string &s1, std::string &s2) {
    return s1+s2 > s2+s1;
}

bool compare_str_by_int(std::string &s1, std::string &s2) {
    if(s1.size() != s2.size()) return s1.size() > s2.size();
    return s1 > s2;
}

int main() {
    std::cin.tie(0);
    std::iostream::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<std::string> reversed_arr;
    for(int i=0; i<n; i++) {
        int strin;
        std::cin >> strin;
        std::string temp = std::to_string(strin);
        std::string reversed_strin = reverse_str(temp);
        reversed_arr.push_back(reversed_strin);
    }
    std::sort(reversed_arr.begin(), reversed_arr.end(), compare_str_by_int);
    reversed_arr.push_back(*reversed_arr.begin());
    std::sort(reversed_arr.begin(), reversed_arr.end(), compare_str);
    std::string ret = "";
    int len = reversed_arr.size();
    for(int i=0; i<len; i++) {
        ret += reversed_arr[i];
    }
    std::cout << reverse_str(ret) << std::endl;
    return 0;
}