#include<stdio.h>

void find_two_unique_numbers(int num[], int size, int* x, int* y) {
    int xor_all = 0;

    printf("List of the numbers:\n");

    for(int i=0; i<size; i++) {
        printf("%d\n", num[i]);
        xor_all ^= num[i];
    }
        
    int right_most_xor_all = xor_all & (-xor_all);

    *x = 0;
    *y = 0;

    for(int i=0; i<size; i++) {
        if (num[i] & right_most_xor_all)
            *x ^= num[i];
        else
            *y ^= num[i];
    }

    return;
}

int main(void) {
    int num[] = {11, 2, 3, 11, 9, 17, 9, 29, 2, 3};
    int size = sizeof(num) / sizeof(num[0]);
    int x, y;

    find_two_unique_numbers(num, size, &x, &y);
    printf("The two unique numers are: %d and %d", x, y);

    return(0);
}