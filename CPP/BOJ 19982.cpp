#include <iostream>
#include <string>

int main() {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    std::string password = "";
    char upper = 'A', lower = 'a', digit = '0';
    for(int i=0; i<a; i++) {
        password += upper++;
        if(upper > 'Z') upper = 'A';
    }
    for(int i=0; i<b; i++) {
        password += lower++;
        if(lower > 'z') lower = 'a';
    }   
    for(int i=0; i<c; i++) {
        password += digit++;
        if(digit > '9') digit = '0';
    }
    while(password.size() < n) {
        password += upper++;
        if(upper > 'Z') upper = 'A';
    }
    std::cout << password << '\n';
    return 0;
}