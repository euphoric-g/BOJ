#include <stdio.h>
#include <string.h>

void plusQ(int index);
void subtract();
int compare();
int len(int op);

char temp[2002];
char a[1001];
char b[1001];
int n[1001] = {0,};
int m[1001] = {0,};
int Q[1001] = {0,};
int a_len, b_len;
int main() {
	fgets(temp, 2002, stdin);
	int count;
	for(int i = 0; i<2002; i++) {
		if(temp[i] != ' ') {
			a[i] = temp[i];
		} else {
			count = i;
			break;
		}
	}
	printf("%c %c %c ", a[0], a[1], a[2]);
	for(int i=0; i<1000; i++) {	// unused : -48
		n[i] = (int)a[i]-48;
		m[i] = (int)b[i]-48;
	}
	for(int i=0; i<len(0); i++) {
		printf("%d", n[i]);
	}
	printf("\n");
	for(int i=0; i<len(2); i++) {
		printf("%d", m[i]);
	}
	printf("\n");
	if(compare() == 2) {
		printf("1\n0\n");
		return 0;
	}
	/*
	while(compare() == 0) {
		subtract();
		plusQ(0);
	}
	for(int i=0; i<len(1); i++) {
		printf("%d", Q[i]);
	}
	printf("\n");
	*/
	return 0;
}

int len(int op) {
	for(int i=0; i<1000; i++) {
		if(op == 0) {
			if(n[999-i] != -48) {
				return 999-i;
			}
		} else if (op == 1) {
			if(Q[999-i] != -48) {
				return 999-i;
			}
		} else if (op == 2) {
			if(m[999-i] != -48) {
				return 999-i;
			}
		}
	}
	return 1;
}

int compare() {	// n이 크면 0, m이 크면 1, 같으면 2를 반환
	for(int i=0; i<1000; i++) {
		if(n[999-i] > m[999-i]) return 0;
		if(n[999-i] < m[999-i]) return 1;
	}
	return 2;
}

void subtract() {
	for(int i=0; i<len(2); i++) {
		n[i] -= m[i];
		if(n[i] < 0 && n[i] != -48) {
			n[i+1]--;
			n[i] += 10;
		}
	}
}

void plusQ(int index) {
	if(Q[index] != 9) Q[index]++;
	else {
		plusQ(index+1);
	}
}
