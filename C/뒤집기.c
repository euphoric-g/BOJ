#include <stdio.h>
#include <math.h>

#define MAX_TRIALS 50
#define MAX_COL 2000
#define MAX_ROW 2000
#define DIVISOR 1000000007

int save(void *states, void *arr, int n, int m);
int flip(void *states, void *arr, int n, int m, int p, int q);
void flip_tile(void *arr, int n, int m, int p, int q, int color);
int comparing_with_objectives(int **arr, int **arrc, int n, int m);
int comparing_with_states(int **arr1, int **arr2, int n, int m);

int saved = 0;

int main() {
	int n,m;
	fscanf(stdin, "%d %d", &n, &m);
	int states[m*n][n][m];
	int arr[n][m];
	for(int i=0; i<n; i++) {
		char temp_col[n+1];
		fscanf(stdin, "%s", temp_col);
		for(int j=0; j<m; j++) {
			if(temp_col[j] == 'W') {
				arr[i][j] = 0;
			} else if(temp_col[j] == 'B') {
				arr[i][j] = 1;			
			}
		}
	}
	int local_arr[n][m];
	save(states, arr, n, m);
	for(int i=1; i<MAX_TRIALS; i++) {
		for(long long k=0; k<(long long)pow(2.0, (float)m*n); k++) {
			if(k==0) {
				for(int x=0; x<n; x++) {
					for(int y=0; y<m; y++) {
						local_arr[x][y] = 0;
					}
				}
			} else {	
				while(k != 0) {
					for(int x=n-1; x>=0; x--) {
						for(int y=m-1; y>=0; y--) {
							local_arr[x][y] = k%2;
							k/=2;
						}
					}
				}
			}
		}
		int select[i];
		for(long long k=0; k<(long long)pow((float)m*n, (float)i); k++) {
			if(k=0) {
				for(int l=0; l<i; l++) {
					select[l] = 0;
				}
			} else {
				while(k!=0) {
					for(int x=i-1; x>=0; i--) {
						select[x] = k%(m*n);
						k /= m*n;
					}
				}
			}
		}
		int saved_arr[n][m];
		for(int k=0; k<n; k++) {
			for(int l=0; l<m; l++) {
				saved_arr[k][l] = local_arr[k][l];
			}
		}
		/*
		for(int k=0; k<i; k++) {
			flip(states, local_arr, n, m, (select[k]-1)/m, (select[k]-1)%m);
		}
		*/
		if(comparing_with_objectives(arr, local_arr, n, m) == 1) {
			save(states, saved_arr, n, m);
		}
	}
	printf("%d\n", saved % DIVISOR);
	return 0;
}

int flip(void *states, void *arr, int n, int m, int p, int q) {
	// p, q 판정하고 정보를 local_arr로 복사한뒤 주변의 타일들에 현재 색상과 함께 flip_tile 신호를 보냄
	// filp_tile 에서는 색상을 변경하고 주변 타일을 확인한다.
	// 뒤집은 후에 목표와 같은지 확인하여 같으면 초기값을 save한다.
	// 이미 같은 값이 저장되어있으면 무시하고 저장되어있지 않으면 저장한다.
	
	if(p>=n || p<0 || q>=m || q<0) {
		return 1;
	}
	int local_arr[n][m];
	int color = *((int *)(arr+p*m*sizeof(int)+q*sizeof(int)));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			local_arr[i][j] = *((int *)(arr+i*m*sizeof(int)+q*sizeof(int)));
		}
	}
	if(local_arr[p][q] == 0) {
		local_arr[p][q] = 1;
	} else if(local_arr[p][q] == 1) {
		local_arr[p][q] = 0;
	}
	flip_tile((void*)local_arr, n, m, p, q, color);
}

void flip_tile(void *arr, int n, int m, int p, int q, int color) {
	if((p>=n || p<0 || q>=m || q<0 || *((int *)(arr+p*m*sizeof(int)+q*sizeof(int))) == color) == 0) {
		if(*((int *)(arr+p*m*sizeof(int)+q*sizeof(int))) == 0) {
			*((int *)(arr+p*m*sizeof(int)+q*sizeof(int))) = 1;
		} else {
			*((int *)(arr+p*m*sizeof(int)+q*sizeof(int))) = 0;
		}
		flip_tile(arr, n,m,p-1,q,color);
		flip_tile(arr, n,m,p+1,q,color);
		flip_tile(arr, n,m,p,q-1,color);
		flip_tile(arr, n,m,p,q+1,color);
	}
}

int save(void * states, void *arr, int n, int m) {
	int is_exist = 0;
	if(saved != 0) {
		for(int i=0; i<saved; i++) {
			if( comparing_with_states((states+i*m*n*sizeof(int)), arr, n, m) == 1 ) {
				is_exist = 1;
				break;
			}
		}
	} else {
		saved++;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				*((int *)(states+saved*n*m*sizeof(int)+i*m*sizeof(int)+j*sizeof(int))) = 
					*((int *)(arr+i*m*sizeof(int)+j*sizeof(int)));
			}
		}
	}
	if(is_exist == 0) {
		saved++;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				*((int *)(states+saved*n*m*sizeof(int)+i*m*sizeof(int)+j*sizeof(int))) = 
					*((int *)(arr+i*m*sizeof(int)+j*sizeof(int)));
			}
		}
	}
	return 0;
}

int comparing_with_objectives(int **arr, int **arrc, int n, int m) {
	int result = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] != arrc[i][j]) {
				result = 0;
			}
		}
	}
	return result;
}

int comparing_with_states(int **arr1, int **arr2, int n, int m) {
	int result = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr1[i][j] != arr2[i][j]) {
				result = 0;
			}
		}
	}
	return result;
}
