#include <stdio.h>

int main() {
	int a, b, ans;
	fscanf(stdin, "%d %d", &a, &b);
	if( a%10 > b%10) {
		ans = a;
	} else if (a%10 < b%10) ans = b;
	else {
		if( (a/10)%10 > (b/10)%10) ans = a;
		else if ( (a/10)%10 < (b/10)%10 ) ans = b;
		else {
			if( (a/100)%10 > (b/100)%10 ) ans = a;
			else if ( (a/100)%10 < (b/100)%10 ) ans = b;
		}
	}
	printf("%d\n", (ans%10)*100 + ((ans/10)%10)*10 + ((ans/100)%10));
	return 0;
}
