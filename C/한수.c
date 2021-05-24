#include <stdio.h>

int is_hansu(int);

int main() {
	int a, count = 0;
	fscanf(stdin, "%d", &a);
	for(int i=1;i<=a; i++) {
		if(is_hansu(i) == 1) count++;
	}
	printf("%d\n", count);
}

int is_hansu(int n) {
	int digit[4];
	int digits = 0;
	while(n!=0) {
		digit[digits++] = n%10;
		n/=10;
	}
	if(digits <= 2) return 1;
	if(digits == 3) {
		if(digit[2]-digit[1] == digit[1]-digit[0]){
			return 1;
		} else {
			return 0;
		}
	}
	if(digits == 4) {
		if(digit[3]-digit[2] == digit[2]-digit[1] && digit[2]-digit[1] == digit[1]-digit[0]) {
			return 1;
		} else {
			return 0;
		}
	}
	return 0;
}