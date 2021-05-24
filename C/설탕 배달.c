#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	if(a%5 == 0) {
		printf("%d\n", a/5);
	} else if (a%5 == 1) {
		printf("%d\n", (a/5)+1);
	} else if (a%5 == 2) {
		if(a==7) {
			printf("-1\n");
		} else {
			printf("%d\n", (a/5)+2);
		}
	} else if (a%5 == 3) {
		printf("%d\n", (a/5)+1);
	} else if (a%5 == 4) {
		if(a==4) {
			printf("-1\n");
		} else {
			printf("%d\n", (a/5)+2);
		}
	}
	return 0;
}
