#include <stdio.h>

int main() {
	int arr[42]={0,};
	int a;
	for(int i=0; i<10; i++) {
		fscanf(stdin, "%d", &a);
		arr[a%42]++;
	}
	a = 0;
	for(int i=0; i<42; i++) {
		if(arr[i] != 0) a++;
	}
	printf("%d\n", a);
	return 0;
}
