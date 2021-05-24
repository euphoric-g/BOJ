#include <cstdio>

int main() {
    int q;
    fscanf(stdin, "%d", &q);
    for(int i=0; i<q; i++) {
        int a;
        fscanf(stdin, "%d", &a);
        printf("%d\n", ((a & (-a)) == a) ? 1 : 0);
    }
}