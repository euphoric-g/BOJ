#include <stdio.h>

int main() {
	int a, b, T;
	fscanf(stdin, "%d", &T);
	for(int i=1; i<=T; i++) {
		fscanf(stdin, "%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
	}
	return 0;
}
