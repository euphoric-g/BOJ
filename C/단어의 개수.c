#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main() {
	char c[MAX];
	fgets(c, MAX, stdin);
	int flag = 0, ans = 0;
	for(int j=0; j<strlen(c)-1; j++) {
		if(c[j] == ' ' && flag == 1) {
			flag = 0;
		} else if(c[j] != ' ' && flag == 0) {
			flag = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
