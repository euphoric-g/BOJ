#include <stdio.h>

int main() {
    int sum = 0, ind = 6, temp;
    while(ind--) {
        scanf("%d", &temp);
        sum += temp;
    }
    printf("%d\n", sum * 5);
}