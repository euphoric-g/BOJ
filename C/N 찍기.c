#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	for(int i = 1; i <= a; i++) {
		printf("%d\n", i);
	}
	return 0;
}
