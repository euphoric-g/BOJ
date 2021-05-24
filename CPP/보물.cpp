#include <iostream>
#include <vector>
#include <algorithm>

class Container {
    public:
    int number;
    int index;
    Container() {}
};

bool compare_by_number_greater(const Container &a, const Container &b) {
    return a.number < b.number;
}

bool compare_by_number_lesser(const Container &a, const Container &b) {
    return a.number > b.number;
}

bool compare_index(const Container &a, const Container &b) {
    return a.index < b.index;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Container> a, b;
    for(int i=0; i<n; i++) {
        Container c = Container();
        std::cin >> c.number;
        c.index = i;
        a.push_back(c);
    }
    for(int i=0; i<n; i++) {
        Container c = Container();
        std::cin >> c.number;
        c.index = i;
        b.push_back(c);
    }
    std::stable_sort(b.begin(), b.end(), compare_by_number_greater);
    std::stable_sort(a.begin(), a.end(), compare_by_number_lesser);
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i].number * b[i].number;
    }
    std::cout << sum << std::endl;
    return 0;
}