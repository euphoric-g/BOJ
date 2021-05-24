#include <stdio.h>
#include <string.h>

int main() {
	char c[101];
	int ans = 0;
	fscanf(stdin, "%s", c);
	for(int i=0; i<strlen(c); i++) {
		if(c[i] == 'c') {
			if(c[i+1] == '=' && i < strlen(c) - 1) {
				ans++;
				i++;
			} else if (c[i+1] == '-' && i < strlen(c) - 1) {
				ans++;
				i++;
			} else {
				ans++;
			}
		} else if (c[i] == 'd') {
			if(c[i+1] == '-' && i < strlen(c) - 1) {
				ans++;
				i++;
			} else if(c[i+1] == 'z' && c[i+2] == '=' && i < strlen(c) -2 ) {
				ans++;
				i += 2;
			} else {
				ans++;
			}
		} else if (c[i] =='l') {
			if(c[i+1] == 'j' && i < strlen(c) - 1 ) {
				ans++;
				i++;
			} else {
			 	ans++;
			}
		} else if (c[i] =='n') {
			if(c[i+1] =='j' && i < strlen(c) - 1 ) {
				ans++;
				i++;
			} else {
				ans++;
			}
		} else if (c[i] =='s') {
			if(c[i+1] =='=' && i < strlen(c) - 1 ) {
				ans++;
				i++;
			} else {
				ans++;
			}
		} else if (c[i] == 'z') {
			if(c[i+1] == '=' && i < strlen(c) - 1) {
				ans++;
				i++;
			} else {
				ans++;
			}
		} else {
			ans++;
		}
	}
	printf("%d\n", ans);
}
