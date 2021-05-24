#include <stdio.h>

int main() {
	int arr[10000] = {0,};
	for(int i=1; i<=10000; i++){
		int k=i;
		int j=i + (i%10) + (i/10)%10 + (i/100)%10 + (i/1000)%10;
		while (j!=k) {
			if(j<10000 && arr[j] == 0) arr[j]=1;
			k=j;
			j=k + (k%10) + (k/10)%10 + (k/100)%10 + (k/1000)%10;
		}
	}
	for(int i=1; i<10000; i++) {
		if(arr[i] == 0) {
			printf("%d\n", i);
		}
	}
}