#include <stdio.h>

int main() {
	int a, b;
	fscanf(stdin, "%d %d", &a, &b);
	for(int i=0; i<a; i++) {
		int c;
		fscanf(stdin, "%d ", &c);
		if(c<b) printf("%d ", c);
	}
	printf("\n");
	return 0;
}
