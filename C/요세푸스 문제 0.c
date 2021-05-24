#include <stdio.h>
#include <stdlib.h>

int eli(int *, int *);
void next(int *, int *);
int N, K;
int main() {
	int *ptr;
	int p = -1;
	ptr = &p;
	fscanf(stdin, "%d %d", &N, &K);
	int *arr = calloc(N, sizeof(int));
	printf("<");
	for(int i=0; i<N-1; i++) {
		printf("%d, ", eli(arr, ptr));
	}
	printf("%d>\n", eli(arr,ptr));
	return 0;
}

int eli(int *arr, int *ptr) {
	for(int i=0; i<K; i++) {
		next(arr, ptr);
	}
	arr[*ptr] = 1;
	return *ptr+1;
}

void next(int *arr, int *ptr) {
	if(*ptr == -1) {
		*ptr = 0;
	}
	else {
		*ptr = (*ptr+1)%N;
		while(arr[*ptr] == 1) {
			*ptr = (*ptr+1)%N;
		}
	}
}
