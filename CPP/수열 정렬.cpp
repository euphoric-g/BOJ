#include <iostream>
#include <vector>
#include <algorithm>

class Container {
    public:
    int num;
    int index;
    int sort;
    Container() {}
    Container(int n, int i) { num = n; index = i; }
};

bool compare_vec(const Container &a, const Container &b) {
    return a.num < b.num;
}

bool compare_index(const Container &a, const Container &b) {
    return a.index < b.index;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Container> vec;
    for(int i=0; i<n; i++) {
        Container c = Container();
        std::cin >> c.num;
        c.index = i;
        vec.push_back(c);
    }
    std::stable_sort(vec.begin(), vec.end(), compare_vec);
    for(int i=0; i<n; i++) {
        vec[i].sort = i;
    }
    std::stable_sort(vec.begin(), vec.end(), compare_index);
    for(int i=0; i<n; i++) {
        std::cout << vec[i].sort << " ";
    }
    std::cout << std::endl;
    return 0;
}