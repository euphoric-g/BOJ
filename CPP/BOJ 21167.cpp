#include <iostream>
#include <string>
#include <cmath>

int main() {
    int R;
    std::string s;
    while(std::cin >> R >> s) {
        double S = std::stod("0" + s);
        int V = (int)(0.5 + sqrt((R*(S+0.16))/0.067));
        std::cout << V << '\n';
    }
}