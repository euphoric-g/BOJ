#include <stdio.h>
#include <string.h>

int seconds(char);

int main() {
	char c[16];
	int sum = 0;
	fscanf(stdin, "%s", c);
	for(int i=0; i<strlen(c); i++) {
		sum += seconds(c[i]);
	}
	printf("%d\n", sum);
	return 0;
}

int seconds(char c) {
	int a = (int)c - 65;
	if(a < 3) {
		// ABC
		return 3;
	} else if ( a < 6) {
		// DEF
		return 4;
	} else if ( a<9) {
		// GHI
		return 5;
	} else if(a<12) {
		// JKL
		return 6;
	} else if (a<15) {
		// MNO
		return 7;
	} else if (a<19) {
		// PQRS
		return 8;
	} else if (a<22) {
		// TUV
		return 9;
	} else if (a<26) {
		// WXYZ
		return 10;
	}
}
