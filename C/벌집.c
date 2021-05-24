#include <stdio.h>

int main() {
	int a, i = 1, sum = 1;
	fscanf(stdin, "%d", &a);
	
	while(1) {
		if(sum>=a) break;
		sum += (i++)*6;
	}
	printf("%d\n", i);
	return 0;
}
