#include <stdio.h>

int main() {
	int a, b;
	fscanf(stdin, "%d %d", &a, &b);
	printf("%.15Lf\n", (long double)a/b);
	return 0;
}
