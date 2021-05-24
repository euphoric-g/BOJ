#include <stdio.h>
#include <string.h>

int main() {
	int n;
	fscanf(stdin, "%d", &n);
	for(int i=0; i<n; i++) {
		int s=0;
		char c[51];
		fscanf(stdin, "%s", c);
		for(int j=0; j<strlen(c) && s>=0; j++) {
			if(c[j]=='(') {
				s++;
			} else if(c[j]==')') {
				s--;
			}
		}
		if(s!=0) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}
