#include <stdio.h>
int main() {
	int a;
	fscanf(stdin, "%d", &a);
	printf("%d\n", (a-1)/5+1);
}
