#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, count = 0;
	fscanf(stdin, "%d", &n);
	int *arr = calloc(n, sizeof(int));
	for(int i=0; i<n; i++) {
		int a;
		fscanf(stdin, "%d", &a);
		if(a==0) {
			count --;
		} else {
			arr[count++] = a;
		}
	}
	int sum = 0;
	for(int i=0; i<count; i++) {
		sum += arr[i];
	}
	printf("%d\n", sum);
}
