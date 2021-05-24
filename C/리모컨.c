#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANNEL 1000000
int test(int t);
int digits(int i);
int n,a;
int available[10] = {1,1,1,1,1,1,1,1,1,1};
int main() {
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%d", &a);
	int *broken = calloc(a, sizeof(int));
	for(int i=0; i<a; i++) {
		fscanf(stdin, "%d", &broken[i]);
		available[broken[i]] = 0;
	}
	free(broken);
	if(a==10 || n == 100) {
		int ans = n>100 ? n-100 : 100 - n;
		printf("%d\n", ans);
		return 0;
	}
	int dif = 2147483647;
	int saved_i = 0;
	int halt_flag = 0;
	for(int i=0; i<MAX_CHANNEL && halt_flag == 0; i++) {
		int t = test(i);
		if(t == 1) {
			if(i==n) {
				saved_i = i;
				halt_flag = 1;
				dif = 0;
			}
			int am = abs(n-i);
			if(am<dif) {
				dif = am;
				saved_i = i;
			} else {
				halt_flag = 1;
			}
		}
	}
	if(dif+digits(saved_i) > abs(n-100)) printf("%d\n", abs(n-100));
	else printf("%d\n", dif + digits(saved_i));
}

int digits(int d) {
	int ans=0;
	if(d==0) return 1;
	while(d!=0) {
		ans++;
		d/=10;
	}
	return ans;
}

int test(int t) {
	int flag = 1;
	if(t==0) {
		if(available[0]==1) return 1;
		else return 0;
	}
	while(t!=0 && flag == 1) {
		if(available[t%10]==0) {
			flag = 0;
		}
		t/=10;
	}
	if(flag == 1) return 1;
	else return 0;
}
