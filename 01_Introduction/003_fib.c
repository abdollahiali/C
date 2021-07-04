#include "stdio.h"

int main(void)
{
    int i, n, x, y, z;
    x = 0;
    y = 1;
    n = 10;
    printf("%d\n", x);
    printf("%d\n", y);
    for(i = 0; i < 10; i++){
        z = x + y;
        printf("%d\n", z);
        x = y;
        y = z;
    }
}
