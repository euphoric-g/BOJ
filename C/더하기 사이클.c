#include <stdio.h>

int main() {
	int a, b, c=0;
	fscanf(stdin, "%d", &a);
	b = a;
	while(1) {
		c++;
		b = (b%10)*10 + ((b/10) + (b%10))%10;
		if(a==b) {
			printf("%d\n", c);
			break;
		}
	}
	return 0;
}
