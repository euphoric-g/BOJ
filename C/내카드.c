#include <stdio.h>
#include <stdlib.h>
// #define DEBUG 1
typedef struct {
	int *arr;
	int init;
	int next;
	int size;
} queue;

void init(queue *pq, int n) {
	pq->arr = calloc(n+1, sizeof(int));
	for(int i=0; i<n; i++) {
		pq->arr[i] = i+1;
	}
	pq->init = 0;
	pq->next = n;
	pq->size = n+1;
}

void push(queue *pq, int x) {
	pq->arr[pq->next] = x;
	pq->next = (pq->next + 1)%pq->size;
}

int pop(queue *pq) {
	int ans =  pq->arr[pq->init];
	pq->init = (pq->init + 1)%pq->size;
	return ans;
}

int size(queue *pq, int n) {
	return pq->init <= pq->next ? pq->next-pq->init : pq->next-pq->init+n;
}

void throw(queue *pq) {
#ifdef DEBUG
	printf("%d thrown.\n", pq->arr[pq->init]);
#endif
	pop(pq);
}

void move_back(queue *pq) {
	push(pq, pop(pq));
}
void f(queue *pq, int n) {
	init(pq, n);
#ifdef DEBUG
	printf("pq->init = %d, pq->next = %d\n", pq->init, pq->next);
#endif
	while(size(pq, pq->size) != 1) {
		throw(pq);
		if(size(pq, pq->size) == 1) break;
		move_back(pq);
	}
	printf("%d\n", pq->arr[pq->init]);
}
int main(){
	int n;
	queue q;
	scanf("%d",&n);
	f(&q, n);
}
