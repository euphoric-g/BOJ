#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50+1
int compare(char *arr, int len, int enlisted, char **p, int i, int* j);

int main() {
	int N;
	fscanf(stdin, "%d", &N);
	char *arr = calloc(N*MAX, sizeof(char));
	int *len = calloc(N, sizeof(int));
	int *words = calloc(MAX, sizeof(int));
	for(int i=0; i<N; i++) {
		char c[MAX+1];
		fscanf(stdin, "%s", c);
		len[i] = strlen(c);
		words[strlen(c)]++;
		for(int j=0; j<strlen(c); j++) {
			arr[i*MAX+j] = c[j];
		}
	}
	char *p[MAX];
	int *enlisted = calloc(MAX, sizeof(int));
	for(int i=1; i<MAX; i++) {
		p[i] = calloc(words[i]*i, sizeof(char));
	}
	for(int i=0; i<N; i++) {
		if(enlisted[len[i]] == 0) {
			for(int j=0; j<len[i]; j++) {
				p[len[i]][enlisted[len[i]]*len[i]+j] = arr[i*MAX+j];
			}
			enlisted[len[i]]++;
		} else {
			int j = 0;
			int noop=0;
			while(compare(arr, len[i], enlisted[len[i]], p, i, &j) == 1) {
				j++;
			}
			if(j!=-1) {
				for(int k=len[i]*enlisted[len[i]]-1; k>=len[i]*j; k--) {
					p[len[i]][k+len[i]] = p[len[i]][k];
				}
				for(int k=0; k<len[i]; k++) {
					p[len[i]][j*len[i]+k] = arr[i*MAX+k];
				}
				enlisted[len[i]]++;
			}
		}
	}
	for(int i=0; i<MAX; i++) {
		for(int j=0; j<enlisted[i]; j++) {
			for(int k=0; k<i; k++) {
				printf("%c", p[i][j*i+k]);
			}
			printf("\n");
		}
	}
	for(int i=1; i<MAX; i++) {
		free(p[i]);
	}
	free(arr);
	free(enlisted);
	free(len);
	free(words);
	return 0;
}

int compare(char *arr, int len, int enlisted, char **p, int i, int* j) {
	if(*j == enlisted+1) {
		return 0;
	}
	for(int x=0; x<len; x++) {
		if(arr[i*MAX+x] > p[len][(*j)*len+x] ) {
			return 1;
		} else if ( arr[i*MAX+x] < p[len][(*j)*len+x] ) {
			return 0;
		}
	}
	*j=-1;
	return 0;
}
