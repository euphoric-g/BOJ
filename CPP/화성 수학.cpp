#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

#define SPACE ' '
#define MULTIPLY_3 '@'
#define PLUS_5 '%'
#define SUBTRACT_7 '#'

void calc(std::string str) {
    std::vector<std::string> ret;
    std::stringstream ss(str);
    double a;
    ss >> a;
    while(!ss.eof()) {
        char op;
        ss >> op;
        if(ss.eof()) break;
        switch(op) {
            case MULTIPLY_3:
            a *= 3;
            break;
            case PLUS_5:
            a += 5;
            break;
            case SUBTRACT_7:
            a -= 7;
            break;
        }
    }
    std::cout << std::fixed << std::setprecision(2) << a << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();
    for(int i=0; i<t; i++) {
        std::string str;
        std::getline(std::cin, str);
        calc(str);
    }
}