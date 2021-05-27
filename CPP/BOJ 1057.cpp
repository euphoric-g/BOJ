#include <iostream>
#include <vector>

int main() {
    int n, jimin, hansu;
    std::cin >> n >> jimin >> hansu;
    auto tie = [&n, &jimin, &hansu]() -> bool {
        return (jimin-1)/2 == (hansu-1)/2 && abs(jimin - hansu) == 1;
    };
    int round = 1;
    while(!tie()) {
        round++;
        jimin = (jimin + 1) / 2;
        hansu = (hansu + 1) / 2;
    }
    std::cout << round << '\n';
    return 0;
}