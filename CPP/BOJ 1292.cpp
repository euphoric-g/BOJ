#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    for(int i=1; i<=50; i++) {
        for(int j=0; j<i; j++) {
            vec.push_back(i);
        }
    }
    int sum = 0;
    int a, b;
    std::cin >> a >> b;
    for(int i=a-1; i<=b-1; i++) {
        sum += vec[i];
    }
    std::cout << sum << '\n';
    return 0;
}