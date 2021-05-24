#include <stdio.h>
#include <math.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<a; i++) {
		long long b,c;
		fscanf(stdin, "%lld %lld", &b, &c);
		if(c-b == 1) printf("1\n");
		else if (c-b == 2) printf("2\n");
		else if (c-b == 3) printf("3\n");
		else {
			long long d = c-b;
			long long j = (long long)sqrt(d-1);
			j = d-j*j <= j ? 2*j : 2*j+1;
			printf("%lld\n", j);
		}
	}
	return 0;
}
