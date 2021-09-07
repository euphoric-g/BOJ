#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::string X, Y;
    while(std::cin >> X >> Y) {
        if(X == "0" && Y == "0") break;
        double x = std::stod(X), y = std::stod(Y);
        double T = 3.14159265358979 * (x*x+y*y)/100;
        std::cout << "The property will be flooded in hour " << ceil(T) << ".\n";
    }
}