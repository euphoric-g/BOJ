#include <stdio.h>

int main() {
	int a, b, c, m;
	int arr[10] = {0,};
	fscanf(stdin, "%d", &a);
	fscanf(stdin, "%d", &b);
	fscanf(stdin, "%d", &c);
	m = a*b*c;
	while ( m != 0 ) {
		arr[m%10]++;
		m/=10;
	}
	for(int i=0; i<10; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
