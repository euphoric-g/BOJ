#include <cstdio>

int main() {
    int limit, speed;
    fscanf(stdin, "%d %d", &limit, &speed);
    if(limit >= speed) {
        printf("Congratulations, you are within the speed limit!\n");
    } else {
        int fine;
        if(speed - limit >= 31) fine = 500;
        else if(speed - limit >= 21) fine = 270;
        else fine = 100;
        printf("You are speeding and your fine is $%d.\n", fine);
    }
    return 0;
}