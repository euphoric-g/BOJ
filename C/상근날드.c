#include <stdio.h>

int main() {
	int arr[5];
	for(int i=0; i<5; i++) {
		fscanf(stdin, "%d", &arr[i]);
	}
	int min[2] = {arr[0], arr[3]};
	for(int i=0; i<5; i++) {
		if( i < 3 && arr[i] < min[0]) min[0] = arr[i];
		if(i >= 3 && arr[i] <min[1]) min[1] = arr[i];	
	}
	printf("%d\n", min[0]+min[1]-50);
	return 0;
}
