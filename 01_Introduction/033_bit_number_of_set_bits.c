#include<stdio.h>

void print_binray(unsigned int val) {
    int n_bits = sizeof(val) * 8;
    for(int i=n_bits-1; i>=0; i--) {
        printf("%d", (val>>i)&1);
        if(i%4==0 && i!= 0)
            printf(" ");
    }
}

int calc_number_of_set_bits(int n) {
    int cntr = 0;

    while(n != 0) {
        cntr++;
        n &= n-1;
    }

    return(cntr);
}

int main(void) {
    int val = 74141789;
    printf("The number is %d.", val);
    printf("\nThe binary representation of the number is: ");
    print_binray(val);
    printf("\nNumber of set bits in the the birnay representation is %d", calc_number_of_set_bits(val));

    return(0);
}