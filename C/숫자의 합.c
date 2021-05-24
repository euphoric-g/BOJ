#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, sum = 0;
	fscanf(stdin, "%d", &a);
	char c[a+1];
	fscanf(stdin, "%s", c);
	for(int i=0; i<a; i++) {
		sum += (int)c[i] - 48;
	}
	printf("%d\n", sum);
	return 0;
}
