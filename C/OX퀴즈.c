#include <stdio.h>
#include <string.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<a; i++) {
		char arr[81];
		int sum = 0, t = 1;
		fscanf(stdin, "%s", arr);
		for(int j=0; j<strlen(arr); j++) {
			if( arr[j] == 'O') {
				sum += t++;
			} else if ( arr[j] == 'X') {
				t = 1;
			}
		}
		printf("%d\n", sum);
	}
}
