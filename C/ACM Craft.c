#include <stdio.h>
#include <stdlib.h>

struct building {
	int needed[100000];
	int need_count;
	int build_time;
};
int search(struct building *b, int obj, int *min_time);
int main() {
	int T;
	fscanf(stdin, "%d", &T);
	for(int i=0; i<T; i++) {
		int N,K,W;
		fscanf(stdin, "%d %d", &N, &K);
		struct building *buildings = calloc(N, sizeof(struct building));
		int *min_time = calloc(N, sizeof(int));
		for(int j=0; j<N; j++) {
			min_time[j] = -1;
			buildings[j].need_count = 0;
			fscanf(stdin, "%d", &buildings[j].build_time);
			if(buildings[j].build_time == 0) buildings[j].build_time = -1;
		}
		for(int j=0; j<K; j++) {
			int a,b;
			fscanf(stdin, "%d %d", &a, &b);
			buildings[b-1].needed[buildings[b-1].need_count++] = a;
		}
		fscanf(stdin, "%d", &W);
		printf("%d\n", search(buildings, W-1, min_time));
		free(buildings);
		free(min_time);
	}
}

int search(struct building *b, int obj, int *min_time) {
	if(b[obj].need_count == 0) {
		min_time[obj] = b[obj].build_time==-1? 0 : b[obj].build_time;
		return min_time[obj];
	} else if (min_time[obj] != -1) {
		return min_time[obj];
	} else {
		int max = 0;
		for(int i=0; i<b[obj].need_count; i++) {
			int t = search(b,b[obj].needed[i]-1,min_time);
			if(t > max) max = t;
		}
		max = b[obj].build_time == -1 ? max : max+b[obj].build_time;
		min_time[obj] = max;
		return max;
	}
}
