#include <stdio.h>

int main() {
	int a, b, T;
	fscanf(stdin, "%d", &T);
	for(int i=0; i<T; i++) {
		fscanf(stdin, "%d %d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}
