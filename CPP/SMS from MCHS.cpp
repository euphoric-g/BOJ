#include <iostream>

int main() {
    int t1, v1, t2, v2;
    std::cin >> t1 >> v1 >> t2 >> v2;
    if(t2 < 0 && v2 >= 10) {
        std::cout << "A storm warning for tomorrow! Be careful and stay home if possible!\n";
    } else if(t1 > t2) {
        std::cout << "MCHS warns! Low temperature is expected tomorrow.\n";
    } else if(v1 < v2) {
        std::cout << "MCHS warns! Strong wind is expected tomorrow.\n";
    } else {
        std::cout << "No message\n";
    }
    return 0;
}