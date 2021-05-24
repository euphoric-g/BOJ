#include <stdio.h>

int search(int, int, double);

int arr[29][29];
double p[4];
int N;
double result;

int main() {
	fscanf(stdin, "%d %lf %lf %lf %lf", &N, &p[0], &p[1], &p[2], &p[3]);
	for(int i=0; i<4; i++) {
		p[i] /= 100;
	}
	search(15,15,1.0);
	printf("%.15f\n", result);
}

int search(int xp, int yp, double f) {
	if(N==0) {
		result += f;
		return 0;
	}
	arr[yp][xp] = 1;
	for(int i=0; i<4; i++) {
		int newX = xp;
		int newY = yp;
		switch(i) {
			case 0 :
			newX++; break;
			case 1 :
			newX--; break;
			case 2 :
			newY--; break;
			case 3 :
			newY++; break;
		}
		if(arr[newX][newY] == 0) {
			N--;
			search(newX,newY,f*p[i]);
			N++;
			arr[newX][newY] = 0;
		}
	}
}
