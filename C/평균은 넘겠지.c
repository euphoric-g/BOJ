#include <stdio.h>

int main() {
	int C, n, sum = 0;
	float avg;
	char a;
	fscanf(stdin, "%d", &C);
	for(int i=0; i<C; i++) {
		int arr[1001] = {0,};
		int index = 0;
		n = 0;
		sum = 0;
		do {
			index--;
			fscanf(stdin, "%d", &arr[n]);
			sum += arr[n++];
			if(n==1) {
				sum -= arr[0];
				index = arr[0];
			}
		} while(index != 0);
		n--;
		avg = (float)sum/n;
		sum = 0;
		for(int j=1; j<=n; j++) {
			if(arr[j] > avg) {
				sum++;
			}
		}
		printf("%.3f\%\n", (float)sum/n*100);
	}
	return 0;
}