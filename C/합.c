#include <stdio.h>

int main() {
	int a, result = 0;
	fscanf(stdin, "%d", &a);
	for(int i=a; i>0; i--) {
		result += i;
	}
	printf("%d\n", result);
	return 0;
}
