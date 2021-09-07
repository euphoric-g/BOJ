#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    for(int i=0; i<input.size(); i++) {
        if(islower(input[i])) {
            input[i] = toupper(input[i]);
        } else {
            input[i] = tolower(input[i]);
        }
    }
    std::cout << input << '\n';
}