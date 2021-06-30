#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string polynomial;
    std::cin >> polynomial;
    auto x_loc = polynomial.find('x', 0);
    int coef_x = 0, constant = 0;
    if(x_loc == std::string::npos) {
        // 상수항만 있는 경우
        constant = std::stoi(polynomial);
    } else {
        coef_x = std::stoi(polynomial.substr(0, x_loc));
        std::string sub = polynomial.substr(x_loc+1, polynomial.size());
        if(sub.size() != 0) {
            constant = std::stoi(sub);
        }
    }
    std::vector<std::string> vec;
    if(coef_x != 0) {
        int coef_xx = coef_x/2;
        std::string pref;
        if(coef_xx == 1) pref = "";
        else if(coef_xx == -1) pref = "-";
        else pref = std::to_string(coef_xx);
        std::string str = pref + "xx";
        if(str[0] != '-') str = '+' + str;
        vec.push_back(str);
    }
    if(constant != 0) {
        std::string pref;
        if(constant == 1) pref = "";
        else if(constant == -1) pref = "-";
        else pref = std::to_string(constant);
        std::string str = pref + "x";
        if(str[0] != '-') str = '+' + str;
        vec.push_back(str);
    }
    vec.push_back("+W");
    for(int i=0; i<vec.size(); i++) {
        if(i==0) {
            if(vec[i][0] == '+') std::cout << vec[i].substr(1, vec[i].size());
            else std::cout << vec[i];
        } else std::cout << vec[i];
    }
    std::cout << '\n';
}