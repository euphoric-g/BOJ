#include <stdio.h>
int main() {
	int a,b,c,d,e;
	fscanf(stdin, "%d", &a);
	fscanf(stdin, "%d", &b);
	fscanf(stdin, "%d", &c);
	fscanf(stdin, "%d", &d);
	fscanf(stdin, "%d", &e);
	printf("%d\n", a+b+c+d+e);
	return 0;
}
