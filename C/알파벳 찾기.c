#include <stdio.h>
#include <string.h>

int main() {
	char c[101];
	int arr[26] = {0, };
	for(int i=0; i<26; i++) {
		arr[i] = -1;
	}
	fscanf(stdin, "%s", c);
	for(int i=0; i<strlen(c); i++) {
		arr[(int)c[i] - 97] = arr[(int)c[i]-97]==-1?i:arr[(int)c[i]-97];
	}
	for(int i=0; i<26; i++) {
		printf("%d", arr[i]);
		if(i != 25) printf(" ");
		else printf("\n");
	}
	return 0;
}
