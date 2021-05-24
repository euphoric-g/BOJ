#include <stdio.h>

int main() {
	int arr[3];
	fscanf(stdin, "%d %d %d", &arr[0], &arr[1], &arr[2]);
	for(int i=0; i<3; i++) {
		for(int j=i; j<3; j++) {
			if(arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("%d\n", arr[1]);
	return 0;
}
