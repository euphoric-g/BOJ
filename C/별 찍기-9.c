#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<a-1; i++) {
		for(int j=0; j<i; j++) {
			printf(" ");
		}
		for(int j=0; j<2*a-2*i-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for(int i=0; i<a; i++) {
		for(int j=0; j<a-i-1; j++) {
			printf(" ");
		}
		for(int j=0; j<2*i+1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
