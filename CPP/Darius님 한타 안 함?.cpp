#include <iostream>
#include <string>

int main() {
    int k, d, a;
    char div;
    std::cin >> k >> div >> d >> div >> a;
    if(k + a < d || d == 0) std::cout << "hasu\n";
    else std::cout << "gosu\n";
}