#include <stdio.h>

int main() {
	long long a,b,c, i=0;
	fscanf(stdin, "%lld %lld %lld", &a, &b, &c);
	if(b>=c) {
		printf("-1\n");
		return 0;
	}
	printf("%lld\n", a/(c-b)+1);
	return 0;
}
