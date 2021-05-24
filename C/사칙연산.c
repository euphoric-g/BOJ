#include <stdio.h>

int main() {
	int a, b;
	fscanf(stdin, "%d %d", &a, &b);
	printf("%d\n", a+b);
	printf("%d\n", a-b);
	printf("%d\n", a*b);	
	printf("%d\n", a/b);
	printf("%d\n", a%b);
}
