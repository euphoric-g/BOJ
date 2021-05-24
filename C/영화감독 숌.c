#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test(int);

int main() {
	int N, a = 666;
	fscanf(stdin, "%d", &N);
	while(N != 0) {
		while ( test(a) == 0 ) {
			a++;
		}
		a++;
		N--;
	}
	printf("%d\n", a-1);
}

int test(int a) {
	int temp = a;
	int sixes = 0;
	int digits = 0;
	while(temp != 0) {
		sixes = temp % 10 == 6 ? sixes+1 : sixes;
		temp/=10;
		digits++;
	}
	if(sixes >=3) {
		char *c = calloc(digits, sizeof(char));
		temp = a;
		int index = 0;
		while(temp != 0) {
			c[index++] = (char)((temp%10)+48);
			temp /= 10;
		}
		for(int i=0; i<digits-2; i++) {
			if(c[i] == '6' && c[i+1] == '6' && c[i+2] == '6') {
				return 1;
			}
		}
		free(c);
	} else {
		return 0;
	}
	return 0;
}
