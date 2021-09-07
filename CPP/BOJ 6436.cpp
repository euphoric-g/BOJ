#include <iostream>

int main() {
    int s, cnt = 0;
    while(std::cin >> s) {
        if(s == 0) break;
        std::cout << "File #" << ++cnt << "\nJohn needs ";
        if(s % (62 * 40000) == 0) std::cout << (s / (62 * 40000));
        else std::cout << (s / (62 * 40000) + 1);
        std::cout << " floppies.\n\n";
    }
}