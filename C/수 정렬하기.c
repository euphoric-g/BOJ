#include <stdio.h>
#include <stdlib.h>

int arr[10001] = {0,};
int main() {
	int n;
	fscanf(stdin, "%d", &n);
	for(int i=0; i<n; i++) {
		int a;
		fscanf(stdin, "%d", &a);
		arr[a]++;
	}
	for(int i=0; i<10001; i++) {
		for(int j=0; j<arr[i]; j++) {
			printf("%d\n", i);
		}
	}
}
