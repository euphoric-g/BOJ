#include <iostream>
#include <vector>

typedef long long data_type;

int main() {
    int n;
    std::cin >> n;
    std::vector<data_type> arr;
    for(int i=0; i<n; i++) {
        data_type elem;
        std::cin >> elem;
        arr.push_back(elem);
    }
    int cur = 0;
    int need = 1;
    int size = 0;
    int max_size = -1;
    while(cur < n) {
        if(arr[cur] >= need) {
            need++;
            max_size = std::max(max_size, ++size);
        } else {
            max_size = std::max(max_size, size = arr[cur]);
            need = size+1;
        }
        cur++;
    }
    std::cout << max_size << "\n";
    return 0;
}