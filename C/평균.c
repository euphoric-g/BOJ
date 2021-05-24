#include <stdio.h>

int main(){
	int N, max = 0, sum = 0;
	fscanf(stdin, "%d", &N);
	int arr[N];
	for(int i=0; i<N; i++) {
		fscanf(stdin, "%d", &arr[i]);
		sum += arr[i];
		max = arr[i] > max ? arr[i] : max;
	}
	printf("%lf\n", (double)sum/max*100/N);
	return 0;
}
