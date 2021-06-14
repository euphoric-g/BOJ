#include <iostream>
#include <random>
#include <map>
#include <time.h>

int main() {
    std::map<int, int> num;
    srand((unsigned)time(NULL));
    while(num.size() < 6) {
        num[rand()%45+1]++;
    }
    for(const auto &item : num) {
        std::cout << item.first << ' ';
    }
    std::cout << '\n';
    return 0;
}