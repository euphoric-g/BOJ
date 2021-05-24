#include <stdio.h>
#include <string.h>

int main() {
	while(1) {
		char c[6];
		fscanf(stdin, "%s", c);
		if(strlen(c) ==1 && c[0] == '0'){
			break;
		}
		if(strlen(c)==1){
			printf("yes\n");
		} else {
			int flag = 1;
			for(int i=0; i<(int)strlen(c)/2; i++) {
				if(c[i] != c[strlen(c)-1-i]) {
					flag = 0;
				}
			}
			if(flag == 1) printf("yes\n");
			else printf("no\n");
		}
	}
}
