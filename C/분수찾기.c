#include <stdio.h>

int main() {
	int a, i=0, sum = 1;
	fscanf(stdin, "%d", &a);
	while(1) {
		sum += i++;
		if(sum>a) {
			sum -= i-1;
			break;
		}
	}
	if(i%2 == 0) {
		printf("%d/%d\n", i-(a%sum+1),a%sum+1);
	} else {
		printf("%d/%d\n", a%sum+1, i-(a%sum+1));
	}
	return 0;
}
