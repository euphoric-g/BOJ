#include <stdio.h>
#include <stdlib.h>

int N, M;
void cal(char*, int, int, int*);
int main() {
	int *pmin;
	int min = -1;
	pmin = &min;
	fscanf(stdin, "%d %d", &N, &M);
	char *arr = malloc(N*M*sizeof(char));
	for(int i=0; i<N; i++) {
		char c[51];
		fscanf(stdin, "%s", c);
		for(int j=0; j<M; j++) {
			*(arr+(i*M+j)*sizeof(char)) = c[j];
		}
	}
	for(int i=0; i<=N-8; i++) {
		for(int j=0; j<=M-8; j++) {
			cal(arr, i, j, pmin);
		}
	}
	printf("%d\n", min);
	free(arr);
	return 0;
}

void cal(char *arr, int a, int b, int* min) {
	char sel[2];
	sel[0] = 'W';
	sel[1] = 'B';
	for(int i=0; i<2; i++) { // arr[a][b] = W, B
		int sum = 0;
		for(int j=a; j<a+8; j++) {
			for(int k=b; k<b+8; k++) {
				if(*(arr+(j*M+k)*sizeof(char)) != sel[(i+(j-a)+(k-b))%2]) {
					sum++;
				}
			}
		}
		if(*min == -1) {
			*min = sum;
		} else if( *min > sum) {
			*min = sum;
		}
	}
}
