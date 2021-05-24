#include <stdio.h>
#include <stdlib.h>

int main() {	
	int a;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<a; i++) {
		int b, c;
		fscanf(stdin, "%d", &b);
		fscanf(stdin, "%d", &c);
		int *p = malloc( sizeof(int) * b * c );
		
	}
}
