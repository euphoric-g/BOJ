#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Date {
    public:
    std::string name;
    int year;
    int month;
    int day;
    Date() {}
    Date(std::string n, int d, int m, int y) {
        year = y;
        month = m;
        day = d;
        name = n;
    }
};

bool compare_date(const Date& a, const Date& b) {
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    if(a.day != b.day) return a.day < b.day;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Date> vec;
    for(int i=0; i<n; i++) {
        std::string name;
        int d, m, y;
        std::cin >> name >> d >> m >> y;
        Date dd = Date(name, d, m, y);
        vec.push_back(dd);
    }
    std::sort(vec.begin(), vec.end(), compare_date);
    std::cout << vec[vec.size()-1].name << std::endl;
    std::cout << vec[0].name << std::endl;
    return 0;
}