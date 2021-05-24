#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void operation(int, int);

struct cell {
	int data;
	struct cell *previous;
	struct cell *next;
	int has_next;
	int has_previous;
};
struct cell *ptr_init;
struct cell *ptr_last;
struct cell cells[10000];
int count = 0;
int last_index = 0;
int main() {
	int n;
	fscanf(stdin, "%d", &n);
	for(int i=0; i<n; i++) {
		char op[11];
		int opcode, x=0;
		fscanf(stdin, "%s", op);
		if(op[0] == 'p' && op[1] == 'u' && op[5] =='b') opcode = 0;
		else if (op[0] == 'p' && op[1] == 'u' && op [5] == 'f') opcode = 6; 
		else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'b') opcode = 1;
		else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'f') opcode = 7;
		else if (op[0] == 's') opcode = 2;
		else if (op[0] == 'e') opcode = 3;
		else if (op[0] == 'f') opcode = 4;
		else if (op[0] == 'b') opcode = 5;
		else opcode = -1;
		if(opcode == 0 || opcode == 6) {
			fscanf(stdin, "%d", &x);
		}
		operation(opcode, x);
	}
	return 0;
}

void operation(int op, int x) {
	switch(op) {
		case 0 :				// push_back
		if(count == 0) {
			cells[last_index].data = x;
			ptr_init = &cells[last_index];
			ptr_last = &cells[last_index];
			count++;
			last_index++;
		} else {
			cells[last_index].data = x;
			cells[last_index].has_previous = 1;
			cells[last_index].previous = ptr_last;
			ptr_last->has_next = 1;
			ptr_last->next = &cells[last_index];
			ptr_last = &cells[last_index];
			count++;
			last_index++;
		}
		break;
		case 1 :				// pop_back
		if(count != 0) {
			printf("%d\n", ptr_last->data);
			if(count != 1) {
				ptr_last->previous->has_next = 0;
				ptr_last = ptr_last->previous;
			}
			count--;
		} else printf("-1\n");
		break;
		case 2 :				// size
		printf("%d\n", count);
		break;
		case 3 :				// empty
		if(count == 0) printf("1\n");
		else printf("0\n");
		break;
		case 4 :				// front
		if(count == 0) printf("-1\n");
		else printf("%d\n", ptr_init->data);
		break;
		case 5 :				// back
		if(count == 0) printf("-1\n");
		else printf("%d\n", ptr_last->data);
		break;
		case 6 :				// push_front
		if(count == 0) {
			cells[last_index].data = x;
			ptr_init = &cells[last_index];
			ptr_last = &cells[last_index];
			count++;
			last_index++;
		} else {
			cells[last_index].data = x;
			cells[last_index].has_next = 1;
			cells[last_index].next = ptr_init;
			ptr_init->has_previous = 1;
			ptr_init->previous = &cells[last_index];
			ptr_init = &cells[last_index];
			count++;
			last_index++;
		}
		break;
		case 7 :				// pop_front
		if(count != 0) {
			printf("%d\n", ptr_init->data);
			if(count != 1) {
				ptr_init->next->has_previous = 0;
				ptr_init = ptr_init->next;
			}
			count--;
		} else printf("-1\n");
		break;
		default :
		break;
	}
}
