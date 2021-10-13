#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int zeros = 0, ones = 0;
    while(!s.empty()) {
        char b = s.back();
        (b == '0' ? zeros : ones)++;
        while(!s.empty() && s.back() == b) s.pop_back();
    }
    cout << min(zeros, ones) << '\n';
}