#include <stdio.h>

int main() {
	int a, b;
	fscanf(stdin, "%d %d", &a, &b);
	if(b<45) {
		if(a==0) a=24;
		printf("%d %d\n", a-1, b+15);
	} else {
		printf("%d %d\n", a, b-45);
	}
	return 0;
}
