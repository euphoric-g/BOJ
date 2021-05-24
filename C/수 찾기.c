#include <stdio.h>
#include <stdlib.h>

void sort(int *, int *, int, int);
void merge(int *, int *, int, int, int);
int n,m;
int main() {
	fscanf(stdin, "%d", &n);
	int *n_arr = calloc(n, sizeof(int));
	int *sorted = calloc(n, sizeof(int));
	for(int i=0; i<n; i++) {
		fscanf(stdin, "%d", &n_arr[i]);
	}
	sort(n_arr, sorted, 0, n-1);
	fscanf(stdin, "%d", &m);
	int *m_arr = calloc(m, sizeof(int));
	for(int i=0; i<m; i++) {
		fscanf(stdin, "%d", &m_arr[i]);
	}
	for(int i=0; i<m; i++) {
		int flag = 1;
		int mid, low = 0, high = n-1;
		while( low <= high && flag == 1) {
			mid = (low+high)/2;
			if( m_arr[i] == sorted[mid] ) {
				flag = 2;		// found
			} else if ( m_arr[i] > sorted[mid] ) {
				low = mid + 1;
			} else if ( m_arr[i] < sorted[mid] ) {
				high = mid - 1;
			}
		}
		if(flag == 2) printf("1\n");
		else printf("0\n");
	}
}

void merge(int *arr, int *sorted, int left, int mid, int right) {
	int i,j,k;
	i=left, j=mid+1; k=left;
	while(i<=mid && j<=right) {
		if(arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
		} else {
			sorted[k++] = arr[j++];
		}
	}
	if(i>mid) {
		for(int l=j; l<=right; l++) {
			sorted[k++] = arr[l];
		}
	} else {
		for(int l=i; l<=mid; l++) {
			sorted[k++] = arr[l];
		}
	}
	for(int l=left; l<= right; l++) {
		arr[l] = sorted[l];
	}
}

void sort(int *arr, int *sorted, int left, int right){
	int mid;
	if(left < right) {
		mid = (left+right)/2;
		sort(arr, sorted, left, mid);
		sort(arr, sorted, mid+1, right);
		merge(arr, sorted, left, mid, right);
	}
}
