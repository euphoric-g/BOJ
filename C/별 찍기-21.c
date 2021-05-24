#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	if(a==1) {
		printf("*\n");
		return 0;
	} else {
		for(int i=0; i<2*a; i++) {
			for(int j=0; j<a; j++) {
				if(i%2 == j%2) {
					printf("*");
				} else {
					printf(" ");
				}
			}
			printf("\n");
		}
	}
}
