#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 2147483647

long long slice(long long *, long long);
long long k,n;
int main() {
	fscanf(stdin, "%lld %lld", &k, &n);
	long long sum = 0;
	long long *k_arr = calloc(k, sizeof(long long));
	for(long long i=0; i<k; i++) {
		fscanf(stdin, "%lld", &k_arr[i]);
		sum += k_arr[i];
	}
	long long min = 1, max = MAX_INT, mid = (min+max)/2;
	long long exit = 0;
	while(exit == 0) {
		// printf("%lld, %lld, %lld\n", min, max, mid);
		long long s_min = slice(k_arr, min);
		long long s_mid = slice(k_arr, mid);
		long long s_max = slice(k_arr, max);
		if(s_min==1 && s_mid == 0) {
			if(mid-min != 1) {
				max = mid - 1;
				mid = (min+max)/2;
			} else {
				mid--;
				exit = 3;
			}
		} else if (s_mid == 1 && s_max == 0) {
			if(max-mid != 1)	{
				min = mid + 1;
				mid = (min+max)/2;
			} else exit = 3;
		} else if ( s_min==0 ) {
			exit = 1;
		} else if ( s_max == 1 ) {
			exit = 2;
		}
	}
	if( exit == 3 ) {
		exit = mid;
	} else exit = exit == 1 ? min - 1 : max;
	printf("%lld\n", exit);
	free(k_arr);
	return 0;
}

long long slice(long long *arr, long long value) {
	long long a = 0;
	for(long long i=0; i<k && a<n; i++) {
		a += arr[i]/value;
	}
	if(a>=n) return 1;
	return 0;
}
