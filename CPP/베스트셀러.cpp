#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> books;
    int n;
    std::cin >> n;
    int max_sell = 0;
    for(int i=0; i<n; i++) {
        std::string str;
        std::cin >> str;
        max_sell = std::max(max_sell, ++books[str]);
    }
    for(const auto &book : books) {
        if(book.second == max_sell) {
            std::cout << book.first << std::endl;
            return 0;
        }
    }
}