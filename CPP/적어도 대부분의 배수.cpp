#include <cstdio>
#include <vector>

int main() {
    std::vector<int> vec;
    for(int i=0; i<5; i++) {
        int get;
        fscanf(stdin, "%d", &get);
        vec.push_back(get);
    }
    int target = 1;
    while(1) {
        int cnt = 0;
        for(const int &num : vec) if(target % num == 0) cnt++;
        if(cnt > 2) {
            printf("%d\n", target);
            return 0;
        }
        target++;
    }
    return 0;
}