#include <stdio.h>

int main() {
	int a[9];
	for(int i=0; i<9; i++) {
		fscanf(stdin, "%d", &a[i]);
	}
	int max = 0;
	for(int i=0; i<9; i++) {
		if(a[i]>a[max]) {
			max = i;
		}
	}
	printf("%d\n%d\n", a[max], max+1);
	return 0;
}
