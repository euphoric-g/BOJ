#include <stdio.h>
#include <stdlib.h>

int min(int, int);
int max(int, int);

int main() {
	int n,m, max=0;
	fscanf(stdin, "%d %d", &n, &m);
	char *arr = calloc(n*m, sizeof(char));
	for(int i=0; i<n; i++) {
		char c[m+1];
		fscanf(stdin, "%s", c);
		for(int j=0; j<m; j++) {
			arr[i*m+j] = c[j];
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i*m+j] == '1') {
				int previous = 1;
				for(int k=max; k<min(m-j, n-i) && previous != 0; k++) {
					int flag = 1;
					if(k==0) { 
					
					} else {
						for(int l=0; l<k && flag != 0; l++) {
							if(arr[i*m+j+l] == '0') {
								flag = 0;
								previous = 0;
							}
						}
					}
					if(flag == 1) {
						int flag2=1;
						if(k==0) {
						
						} else {
							for(int p=0; p<(k+1) && flag2 != 0; p++) {
								for(int q=0; q<(k+1) && flag2 != 0; q++) {
									if(arr[(i+p)*m+(j+q)] == '0') {
										flag2 = 0;
										previous = 0;
									}
								}
							}
						}
						if(flag2 == 1) {
							if(k==0 && max == 0) {
								max = 1;
								previous = 1;
							} else if(max < (k+1)) {
								max = (k+1);
								previous = 1;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", max*max);
}

int min(int a, int b) { return a<b?a:b; }
int max(int a, int b) { return a>b?a:b; }
