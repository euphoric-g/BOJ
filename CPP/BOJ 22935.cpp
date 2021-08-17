#include <iostream>
#include <vector>
#include <string>

const std::string sleep = "V";
const std::string strawberry = "딸기";

int main() {
    auto tell = [](const int &n) -> void {
        if(n) std::cout << strawberry;
        else std::cout << sleep;
    };
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        n = (n-1) % 28 + 1;
        if(n >= 16) n = 30 - n;
        tell((n >> 3) % 2);
        tell((n >> 2) % 2);
        tell((n >> 1) % 2);
        tell((n >> 0) % 2);
        std::cout << '\n';
    }
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
29282726252423222120 19 18 17 16
  303132333435363738 39 40 41 42 43
57565554535251504948 47 46 45 44
*/