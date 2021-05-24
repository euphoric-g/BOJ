#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char c[100];
	fscanf(stdin, "%s", c);
	srand((unsigned int)time(NULL));
	printf("%d\n", rand()%2);
}
