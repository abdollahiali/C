#include <stdio.h>

int main()
{
    int i= -1, i_res;
    unsigned int ui = 0, u_res;
    

    

    printf("When using int and unsigned in an operation, then int will automatically be casted into unsigned int\nand this can make trouble in relational expressions as shown below:\n");

    printf("\ni = %d, ui = %u\n", i, ui);

    if(i>ui)
        printf("\ni is greater than ui.\n");
    if(i <= (int)ui)
        printf("\nThe above statement is wrong.\n");
    
    
    printf("\n\nNext, let's have a look at summation of i + ui.\n");
    i_res = i + ui;
    u_res = i + ui;
    
    printf("\nwhen the result is stored in an int:          %d", i_res);
    printf("\nwhen the result is stored in an unsigned int: %u\n", u_res);

    return 0;
}
