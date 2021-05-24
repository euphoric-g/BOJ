#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <random>

int arr[1000000];
int arr2[1000000];

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    auto program_start = clock();
    std::ofstream os;
    os.tie(0);
    os.open("input.txt");
    for(int i=0; i<1000000; i++) {
        os << rand() << ' ';
    }
    os.close();
    std::ifstream is("input.txt");
    is.tie(0);
    int cnt = 0;
    while(is >> arr[cnt++]) {}
    for(int i=0; i<cnt; i++) {
        arr2[i] = arr[i];
    }
    is.close();
    auto program_end = clock();
    std::cout << "preparing : " << (double)(program_end - program_start) / CLOCKS_PER_SEC << '\n';
    auto start = clock();
    qsort(arr, cnt, sizeof(int), compare);
    auto finish = clock();
    std::cout << "C qsort : " << (double)(finish - start) / CLOCKS_PER_SEC << '\n';
    start = clock();
    std::sort(arr, arr+cnt);
    finish = clock();
    std::cout << "C++ std::sort : " << (double)(finish - start) / CLOCKS_PER_SEC << '\n';
    return 0;
}