#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	if( ((a%4==0)&&(a%100!=0))||(a%400==0)) {
		printf("1\n");
	} else {
		printf("0\n");
	}
	return 0;
}
