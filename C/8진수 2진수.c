#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *c = calloc(333334, sizeof(char));
	fscanf(stdin, "%s", c);
	int f=0;
	if(strlen(c)==1 && c[0] == '0') {
		printf("0\n");
		return 0;
	}
	int len = strlen(c);
	for(int i=0; i<len; i++) {
		if(f==0 && c[i] != 0) {
			f=1;
			int _4 = (c[i]-48)/4;
			int _2 = ((c[i]-48)%4)/2;
			int _1 = (c[i]-48)%2;
			if(_4 == 0 && _2 == 0 && _1 == 1) printf("1");
			else if (_4==0 && _2 == 1) printf("1%d",_1);
			else if (_4==1) printf("1%d%d", _2, _1);
		} else {
			printf("%d%d%d", (c[i]-48)/4, ((c[i]-48)%4)/2, (c[i]-48)%2);
		}
	}
	free(c);
	printf("\n");
}
