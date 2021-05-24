#include <stdio.h>

struct data {
	int zeros;
	int ones;
	int available;
};
struct data d[41];
struct data fibonacci(int);
int main() {
	for(int i=0; i<41; i++) {
		d[i].available = 0;
		d[i].zeros=0;
		d[i].ones=0;
	}
	d[0].available = 1;
	d[0].zeros=1;
	d[1].available = 1;
	d[1].ones=1;
	int t;
	fscanf(stdin, "%d", &t);
	for(int i=0; i<t; i++) {
		int a;
		fscanf(stdin, "%d", &a);
		struct data f = fibonacci(a);
		printf("%d %d\n", f.zeros, f.ones);
	}
}

struct data fibonacci(int n) {
	struct data f;
	f.zeros = 0;
	f.ones = 0;
	if(n==0) {
		f.zeros=1;
	} else if (n==1) {
		f.ones = 1;
	} else if (d[n].available == 1) {
		f.zeros = d[n].zeros;
		f.ones = d[n].ones;
	} else if (d[n].available == 0) {
		f.zeros = fibonacci(n-1).zeros + fibonacci(n-2).zeros;
		f.ones = fibonacci(n-1).ones + fibonacci(n-2).ones;
		d[n].zeros = f.zeros;
		d[n].ones = f.ones;
		d[n].available = 1;
	}
	return f;
}
