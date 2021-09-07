#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;
    for(int i=0; i<a.size(); i++) {
        if(a[i] == '6') a[i] = '5';
    }
    for(int i=0; i<b.size(); i++) {
        if(b[i] == '6') b[i] = '5';
    }
    int min_a = std::stoi(a), min_b = std::stoi(b);
    for(int i=0; i<a.size(); i++) {
        if(a[i] == '5') a[i] = '6';
    }
    for(int i=0; i<b.size(); i++) {
        if(b[i] == '5') b[i] = '6';
    }
    int max_a = std::stoi(a), max_b = std::stoi(b);
    std::cout << min_a + min_b << ' ' << max_a + max_b << '\n';
}