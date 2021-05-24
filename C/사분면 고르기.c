#include <stdio.h>

int main() {
	int a, b, result;
	fscanf(stdin, "%d", &a);
	fscanf(stdin, "%d", &b);
	if(a>0) {
		if(b>0) {
			result = 1;
		} else if(b<0) {
			result = 4;
		}
	} else {
		if(b>0) {
			result = 2;
		} else if(b<0) {
			result = 3;
		}
	}
	printf("%d\n", result);
	return 0;
}
