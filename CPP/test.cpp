#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

typedef struct jewel {
	int weight;
	int value;
} jewel;
int N, K, bag[300000], pq[300000];
jewel j[300000];
long long ans = 0;

int compare(const void* a, const void* b) {	
	return *(int*)a - *(int*)b; 
}
int compare2(const void* a, const void* b) { 
	return  (*(jewel*)a).weight - (*(jewel*)b).weight;
}
bool comp_j(const jewel &a, const jewel &b) {
	return a.weight < b.weight;
}

void push(int item, int index) { // max heap
	while (index != 1 && item > pq[index / 2]) {
		pq[index] = pq[index / 2];
		index /= 2;
	}	
	pq[index] = item;
}
int del(int num) {
	int par = 1, ch = 2, first = pq[1];
	std::swap(pq[1], pq[num--]);
	while (ch<=num && pq[par]<pq[ch]) {
		if (ch<num && pq[ch]<pq[ch + 1]) ch++; //더 큰 값을 올려야 됨
		std::swap(pq[par], pq[ch]);
		par = ch;
		ch *= 2;
	}
	return first;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d %d", &j[i].weight, &j[i].value);
	for (int i = 0; i < K; i++) scanf("%d", &bag[i]);
	qsort(j, N, sizeof(jewel), compare2); //보석 무게 오름차순 정렬
	qsort(bag, K, sizeof(int), compare); // 가방 무게 오름차순 정렬
	for(int i=0; i<N; i++) printf("(%d %d) ", j[i].weight, j[i].value);
	printf("\n");
	for(int i=0; i<K; i++) printf("%d ", bag[i]);
	printf("\n");
	int jewelindex = 0, index=0;
	for (int i = 0; i < K; i++) {
		while (jewelindex<N && j[jewelindex].weight <= bag[i]) {
			push(j[jewelindex++].value, ++index);
			printf("bag[%d] : ", i);
			for(int i=0; i<=N; i++) {
				printf("%d ", pq[i]);
			}
			printf("\n");
		}
		ans += del(index--);
		printf("ans = %lld\n", ans);
	}
	printf("%lld", ans);
}
/* 보석은 무게 오름차순, 가방은 무게 오름차순 정렬
* 모든 가방에 담을 수 있는 보석 중 가장 비싼 보석을 넣으면 된다.
* A가방 무게와 같거나 가벼운 보석까지 보석을 탐색해서 그 가격으로 max heap을 만들고 root 원소를 pop해서 답에 더한다.
* 모든 가방에 대해 같은 작업을 한다.
*/