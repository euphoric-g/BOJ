#include <stdio.h>
#include <stdlib.h>

int r = 31;
int M = 1234567891;
long long power(int, int);
int main() {
	int L;
	fscanf(stdin, "%d", &L);
	char *c = calloc(L+1, sizeof(char));
	fscanf(stdin, "%s", c);
	int *n = calloc(L, sizeof(int));
	for(int i=0; i<L; i++) {
		n[i] = (int)c[i]-97+1;	
	}
	free(c);
	long long ans = 0;
	for(int i=0; i<L; i++) {
		ans = (ans%M+(n[i]*power(r, i))%M)%M;
	}
	free(n);
	printf("%lld\n", ans);
}

long long power(int r, int i) {
	long long ans = 1;
	for(int a=0; a<i; a++) {
		ans = ((ans%M) * r) % M;
	}
	return ans;
}
