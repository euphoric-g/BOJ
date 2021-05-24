#include <stdio.h>

int main() {
	int a, b, c;
	fscanf(stdin, "%d %d %d", &a, &b, &c);
	if( c-(a-b)*((c-b)/(a-b)) > b) {
		printf("%d\n", (c-b)/(a-b)+1);
	} else {
		printf("%d\n", (c-b)/(a-b));
	}
	return 0;
}
