#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void operation(int, int);

int queue[10000] = {0,};
int init = 0, next = 0;

int main() {
	int n;
	fscanf(stdin, "%d", &n);
	for(int i=0; i<n; i++) {
		char op[6];
		int opcode, x=0;
		fscanf(stdin, "%s", op);
		if(op[0] == 'p' && op[1] == 'u') {
			opcode = 0;
		} else if (op[0] == 'p' && op[1] == 'o') opcode = 1;
		else if (op[0] == 's') opcode = 2;
		else if (op[0] == 'e') opcode = 3;
		else if (op[0] == 'f') opcode = 4;
		else if (op[0] == 'b') opcode = 5;
		else opcode = -1;
		if(opcode == 0) {
			fscanf(stdin, "%d", &x);
		}
		operation(opcode, x);
	}
}

void operation(int op, int x) {
	switch(op) {
		case 0 :				// push
		queue[next++] = x;
		break;
		case 1 :				// pop
		if(init < next) printf("%d\n", queue[init++]);
		else printf("-1\n");
		break;
		case 2 :				// size
		printf("%d\n", next-init);
		break;
		case 3 :				// empty
		if(next-init == 0) printf("1\n");
		else printf("0\n");
		break;
		case 4 :				// front
		if(next-init == 0) printf("-1\n");
		else printf("%d\n", queue[init]);
		break;
		case 5 :				// back
		if(next-init == 0) printf("-1\n");
		else printf("%d\n", queue[next-1]);
		break;
		default :
		break;
	}
}
