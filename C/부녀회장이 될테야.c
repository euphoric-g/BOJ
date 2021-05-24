#include <stdio.h>
int num(int, int);

int main() {
	int N;
	fscanf(stdin, "%d", &N);
	for(int i=0; i<N; i++) {
		int a,b;
		fscanf(stdin, "%d", &a);
		fscanf(stdin, "%d", &b);
		printf("%d\n", num(a,b));
	}
}

int num(int a, int b) {
	if(a==0) return b;
	else {
		int sum = 0;
		for(int i=1; i<=b; i++) {
			sum += num(a-1,i);
		}
		return sum;
	}
}
