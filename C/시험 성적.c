#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	if(a>89) {
		printf("A\n");	
	} else if (a > 79) {
		printf("B\n");
	} else if (a > 69) {
		printf("C\n");
	} else if (a > 59) {
		printf("D\n");
	} else {
		printf("F\n");
	}
	return 0;
}
