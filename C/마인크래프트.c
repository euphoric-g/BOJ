#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, B;
	fscanf(stdin, "%d %d %d", &N, &M, &B);
	int *arr = calloc(N*M, sizeof(int));
	int h_min, h_max;
	for(int i=0; i<N*M; i++) {
		fscanf(stdin, "%d", &arr[i]);
		if(i==0) {
			h_min = arr[i];
			h_max = arr[i];
		} else {
			if(h_min > arr[i]) h_min = arr[i];
			else if (h_max < arr[i]) h_max = arr[i];
		}
	}
	int height, t_min=2147483647;
	for(int i=h_min; i<=h_max; i++) {
		int local_B=B;
		int sum=0;
		int time=0;
		int flag = 0;
		for(int j=0; j<N*M && time <= t_min; j++) {
			sum += arr[j]-i;
			time = arr[j]-i>0 ? time+2*(arr[j]-i) : time+(i-arr[j]);
			local_B += arr[j]-i;
			flag = time <= t_min ? j : j-1;
			// 파야하면 +, 채워야하면 -
		}
		if(!(sum < 0 && local_B < 0) && flag == N*M-1) { // 인벤토리가 모자라지 않고 최소시간이라면
			height = i;
			t_min = time;
		}
	}
	printf("%d %d\n", t_min, height);
	return 0;
}
