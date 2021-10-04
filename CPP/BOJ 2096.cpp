#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int dp_max[3] = {0, 0, 0};
    int dp_min[3] = {0, 0, 0};
    for(int i=0; i<n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int dma = dp_max[0], dmb = dp_max[1], dmc = dp_max[2];
        int dna = dp_min[0], dnb = dp_min[1], dnc = dp_min[2];
        dp_max[0] = std::max(dma + a, dmb + a);
        dp_max[1] = std::max(std::max(dma + b, dmb + b), dmc + b);
        dp_max[2] = std::max(dmb + c, dmc + c);
        dp_min[0] = std::min(dna + a, dnb + a);
        dp_min[1] = std::min(std::min(dna + b, dnb + b), dnc + b);
        dp_min[2] = std::min(dnb + c, dnc + c);
    }
    std::cout << std::max(std::max(dp_max[0], dp_max[1]), dp_max[2]) << ' ' << std::min(std::min(dp_min[0], dp_min[1]), dp_min[2]) << '\n';
}