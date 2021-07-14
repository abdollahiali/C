#include <stdio.h>

union utype{
    int i;
    float f;
} un;

int main()

{
    un.f = 1.0;

    printf("Bit representation of float number of %f is %x\n", un.f, un.i);

    return 0;
}