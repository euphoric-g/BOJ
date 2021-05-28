#include <iostream>
#include <algorithm>
#include <string>

class Data {
    public:
    int korean, english, math;
    std::string name;
    Data() {}
    Data(int k, int e, int m, std::string n) {
        korean = k, english = e, math = m, name = n;
    }
};

Data *arr;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    arr = new Data[n];
    for(int i=0; i<n; i++) {
        std::cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;
    }
    std::sort(arr, arr+n, [](const Data &a, const Data &b) -> bool {
        if(a.korean != b.korean) return a.korean > b.korean;
        if(a.english != b.english) return a.english < b.english;
        if(a.math != b.math) return a.math > b.math;
        return a.name < b.name;
    });
    for(int i=0; i<n; i++) {
        std::cout << arr[i].name << '\n';
    }
    return 0;
}