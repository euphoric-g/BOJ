#include <stdio.h>
#include <string.h>

int main() {
	int b;
	fscanf(stdin, "%d", &b);
	for(int k=0; k<b; k++) {
		int a=0;
		fscanf(stdin, "%d ", &a);
		char c[a+1];
		fscanf(stdin, "%s", c);
		for(int i=0; i<strlen(c); i++) {
			for(int j=0; j<a; j++) {
				printf("%c", c[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
