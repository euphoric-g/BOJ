#include <iostream>
#include <vector>

// #define DEBUG

const int EVEN = 0;
const int ODD = 1;

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);
    int n, k;
    std::cin >> n >> k;
    auto judge = [](const int &n) -> bool { return n % 2; };
    std::vector<int> vec;
    for(int i=0; i<n; i++) {
        int num;
        std::cin >> num;
        vec.push_back(num);
    }
    int start = 0, last = 0, maxlen = 0;
    int len = judge(vec[0]) == EVEN ? 1 : 0;
    int skips = judge(vec[0]) == ODD ? 1 : 0;
    maxlen = std::max(maxlen, len);
    while(1) {
        if(skips <= k) {
            if(++last >= vec.size()) break;
#ifdef DEBUG
            std::cout << "[" << start << ", " << last << "] : ";
#endif
            if(judge(vec[last]) == EVEN) {
                maxlen = std::max(maxlen, ++len);
#ifdef DEBUG
                std::cout << "maxlen = " << maxlen << '\n';
#endif
            } else {
                skips++;
            }
#ifdef DEBUG
            std::cout << "len = " << len << ", " << "skips = " << skips << '\n';
#endif
        } else {
            if(judge(vec[start]) == EVEN) {
                len--;
            } else {
                skips--;
            }
            start++;
#ifdef DEBUG
            std::cout << "[" << start << ", " << last << "] : ";
            std::cout << "len = " << len << ", " << "skips = " << skips << '\n';
#endif
        }
    }
    std::cout << maxlen << '\n';
}