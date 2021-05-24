#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> data;

bool compare(const data &a, const data &b) {
    return a.first < b.first;
}

int main() {
    int n;
    fscanf(stdin, "%d", &n);
    std::vector<data> vec;
    for(int i=1; i<=n; i++) {
        int in;
        fscanf(stdin, "%d", &in);
        vec.push_back(data(in, i));
    }
    std::stable_sort(vec.begin(), vec.end(), compare);
    int distance = 0;
    for(int i=1; i<=n; i++) {
        distance = std::max(distance, vec[i-1].second - i + 1);
    }
    printf("%d\n", distance);
}