#include<stdio.h>

int main() {
    int a = 29;
    int b = 31;

    printf("\nOriginal numbers:\na = %d, b = %d", a, b);

    a = a^b;
    b = b^a;
    a = a^b;

    printf("\n\nAfter swap using XOR:\na = %d, b = %d", a, b);
    
    return(0);
}