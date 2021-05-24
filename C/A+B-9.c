#include <stdio.h>
#include <string.h>

int main() {
	int A[10001];
	int B[10001];
	int len[2];
	char c[10002];
	fscanf(stdin, "%s", c);
	if(c[0] == '-') {
		for(int i=strlen(c); i>=1; i--) {
			A[i-1] = 0-(int)(c[i]-48);
		}
		len[0] = strlen(c)-1;
	} else {
		for(int i=strlen(c); i>=0; i--) {
			A[i] = (int)c[i]-48;
		}
		len[0] = strlen(c);
	}
	fscanf(stdin, "%s", c);
	if(c[0] == '-') {
		for(int i=strlen(c); i>=1; i--) {
			B[i-1] = 0-(int)(c[i]-48);
		}
		len[1] = strlen(c)-1;
	} else {
		for(int i=strlen(c); i>=0; i--) {
			B[i] = (int)c[i]-48;
		}
		len[1] = strlen(c);
	}
	int large_len = len[0] < len[1] ? len[1] : len[0];
	for(int i=large_len; i>=0; i--) {
		A[i] = A[i]+B[i];
		if(A[i] > 10) {
			A[i] -= 10;
			A[i-1] += 1;
		}
	}
	int is_neg = 0;
	if(A[large_len] < 0) {
		for(int i=0; i<large_len; i++) {
			A[i] = -A[i];
		}
		is_neg = 1;
	}
	for(int i=0; i<large_len; i++) {
		if(A[i] < 0) {
			A[i]+=10;
			A[i+1] -= 1;
		}
	}
	int f = 0;
	if(is_neg == 1) printf("-");
	for(int i=large_len+1; i>=0; i--) {
		if(A[i]==0 && f==0) {
		
		} else f = 1;
		if(f==1) {
			printf("%d", A[i]);
		}
	}
	printf("\n");
}
