#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<a; i++) {
		int H, W, N;
		fscanf(stdin, "%d %d %d", &H, &W, &N);
		if( ((N-1)/H+1)/10 == 0) {
			printf("%d0%d\n", (N-H*((N-1)/H)), (N-1)/H+1);
		} else {
			printf("%d%d\n", (N-H*((N-1)/H)), (N-1)/H+1);
		}
	}
	return 0;
}
