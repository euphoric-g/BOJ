#include <iostream>
#include <tuple>

std::tuple<int, int, int> extended_Euclidean(int a, int b) {
    if(b == 0) {
        return std::make_tuple(a, 1, 0);
    }
    int gcd, x, y;
    std::tie(gcd, x, y) = extended_Euclidean(b, a%b);
    return std::make_tuple(gcd, y, x-(a/b)*y);
}

int main() {
    int M, N, x, y;
    std::cin >> M >> N >> x >> y;
    int gcd, t1, t2;
    std::tie(gcd, t1, t2) = extended_Euclidean(M, N);
    int xydif = x-y;
    if(xydif < 0) xydif = -xydif;
    if(xydif % gcd != 0) {
        std::cout << "-1\n";
        return 0;
    }

    /*
        x == 3 mod 5
        x == 13 mod 15
        
        m = 75
        N1 = 15
        N2 = 5

        15s1 == 0 (mod 5)
        5s2 == 5s2 (mod 15)
        

        year z;
        z % M = x
        z % N = y

    */
}