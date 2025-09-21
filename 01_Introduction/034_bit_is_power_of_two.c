#include<stdio.h>
//#include<stdbool.h>


int is_power_of_two(int n) {
    return( (n>0) && ((n&(n-1)) == 0));
}

int main(void) {
    int num[] = {0, 1, 2, 3, 4, 5, 17, 32, 64, 128, 129, 217, 512};

    int size = sizeof(num) / sizeof(num[0]);

    for(int i=0; i<size; i++)
    printf("Is %d power of two: %d\n", num[i], is_power_of_two(num[i]));

    return(0);
}