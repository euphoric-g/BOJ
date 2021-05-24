#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<2*a-1; i++) {
		if(i<a) {
			for(int j=0; j<i+1; j++) {
				printf("*");
			}
			printf("\n");
		} else {
			for(int j=0; j<2*a-i-1; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
