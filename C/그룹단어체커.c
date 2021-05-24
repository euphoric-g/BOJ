#include <stdio.h>
#include <string.h>

int checker(char[], int len);
int main() {
	int a, ans = 0;
	fscanf(stdin, "%d", &a);
	for(int i=0; i<a; i++) {
		char c[101];
		fscanf(stdin, "%s", c);
		if(checker(c, strlen(c)) == 1) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

int checker(char c[], int len) {
	int t = 0;
	int p = (int)c[0]-97;
	int arr[26] = {0,};
	// 이전 단어의 인덱스를 p에 저장
	// 해당 문자의 갯수를 arr에 저장, 현재 연속된 문자의 갯수를 t에 저장
	// 다른 경우 발생시 0 반환
	for(int i=0; i<len; i++) {
		// 이전 문자와 다른 문자가 들어온 경우 t 초기화
		if( (int)c[i] - 97 != p ) t=0;
		
		// 연속으로 들어오고있는 경우 t 증가
		if( arr[ (int)c[i]-97 ] == t) {
			arr[ (int)c[i]-97 ]++;
			t++;
		} else {
			return 0;
		}
		// 현재 문자의 인덱스를 p에 대입
		p = (int)c[i]-97;
	}
	return 1;
}
