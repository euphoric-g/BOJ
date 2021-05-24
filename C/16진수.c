#include <stdio.h>
#include <string.h>

int cv(char ch);

int main() {
	char c[7];
	int sum = 0;
	fscanf(stdin, "%s", c);
	for(int i=0; i<strlen(c); i++) {
		sum += cv(c[i]) << (4*(strlen(c)-1)-4*i);
	}
	printf("%d\n", sum);
	return 0;
}

int cv(char ch) {
	if(ch=='0') return 0;
	else if(ch=='1') return 1;
	else if (ch=='2') return 2;
	else if (ch=='3') return 3;
	else if (ch=='4') return 4;
	else if (ch=='5') return 5;
	else if (ch=='6') return 6;
	else if (ch=='7') return 7;
	else if (ch=='8') return 8;
	else if (ch=='9') return 9;
	else if (ch=='A') return 10;
	else if (ch=='B') return 11;
	else if (ch=='C') return 12;
	else if (ch=='D') return 13;
	else if (ch=='E') return 14;
	else if (ch=='F') return 15;
	else return 0;
}
