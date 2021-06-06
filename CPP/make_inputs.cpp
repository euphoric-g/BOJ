#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE *fp = fopen("input.txt", "w+");
    fprintf(fp, "20\n");
    srand((unsigned int)time(NULL));
    for(int i=0; i<20; i++) fprintf(fp, "%d\n", (rand()%1000)+1);
    fclose(fp);
    return 0;
}