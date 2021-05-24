#include <cstdio>

int main() {
    int k;
    scanf("%d", &k);
    double commission = 25 + (double)k / 100;
    if(commission < 100) commission = 100;
    if(commission > 2000) commission = 2000;
    printf("%.2lf\n", commission);
    return 0;
}