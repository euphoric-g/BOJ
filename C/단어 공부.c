#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main() {
	char c[MAX];
	int arr[26];
	fscanf(stdin, "%s", c);
	for(int i=0; i<strlen(c); i++) {
		if((int)c[i] < 91) arr[(int)c[i]-65]++;
		else if((int)c[i] >= 97) arr[(int)c[i]-97]++;
	}
	int max_index = 0;
	int max = 0;
	int flag = 0;
	for(int i=0; i<26; i++) {
		if(max < arr[i]) {
			max_index = i;
			max = arr[i];
			flag = 0;
		} else if (max == arr[i]) {
			flag++;
		}
	}
	if(flag != 0) {
		printf("?\n");
	} else {
		printf("%c\n", (char)(max_index+65));
	}
	return 0;
}
