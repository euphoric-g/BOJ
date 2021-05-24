#include <stdio.h>
int factorial(int);
int main() {
	int n, r;
	fscanf(stdin, "%d %d", &n, &r);
	printf("%d\n", factorial(n)/(factorial(n-r)*factorial(r)));
}

int factorial(int n) {
	if(n==1 || n==0) return 1;
	else return n*factorial(n-1);
}
