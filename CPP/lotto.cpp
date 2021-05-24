#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <cstring>
#include <string>

int main() {
    for(int z=0; z<5; z++) {
    std::uniform_int_distribution<int> distr(1, 45);
    std::vector<int> vec;
    vec.resize(45);
    for(int i=0; i<45; i++) vec[i] = i+1;
    std::random_device random_dev;
    std::mt19937 generator(random_dev());
    std::shuffle(vec.begin(), vec.end(), generator);
    for(int i=0; i<6; i++) {
        std::cout << vec[i] << ((i == 5) ? "\n" : " ");
    }
    }
    return 0;
}