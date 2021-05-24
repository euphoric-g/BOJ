#include <stdio.h>

int main() {
	int min, max, N;
	fscanf(stdin, "%d", &N);
	int arr[N];
	for(int i=0; i<N-1; i++) {
		fscanf(stdin, "%d ", &arr[i]);
	}
	fscanf(stdin, "%d", &arr[N-1]);
	min = arr[0];
	max = arr[0];
	for(int i=0; i<N; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
		if(arr[i] < min) {
			min = arr[i];
		}
	}
	printf("%d %d\n", min, max);
	return 0;
}
