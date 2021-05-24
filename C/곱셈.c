#include <stdio.h>

int main() {
	int a, b;
	fscanf(stdin, "%d", &a);
	fscanf(stdin, "%d", &b);
	printf("%d\n", a*(b%10));
	printf("%d\n", a*((b/10)%10));
	printf("%d\n", a*((b/100)%10));
	printf("%d\n", a*b);
	return 0;
}
