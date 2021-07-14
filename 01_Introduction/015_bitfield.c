#include <stdio.h>

struct bit_field {
unsigned bit1: 1;
unsigned bit2: 1;
unsigned num: 3; // can take from 0 to 7
} btf;

int main()

{
    btf.bit1 = 0;
    btf.bit2 = 1;
    btf.num = 7;
    printf("\
    struct bit_field {\n\
\tunsigned bit1: 1;\n\
\tunsigned bit2: 1;\n\
\tunsigned num: 3; \n\
} btf;\n");

    printf("Size of bitfield variable is %ld bytes.\n", sizeof(btf));
    printf("Note that we only have used 5 bits of the bitfield structre.\
    \nWe can proceed up to 32 bits and the size of the bitfield still remain 4 bytes.\n\
    However, if we proceed to 33 bits, then the size of the bitfield would increase to 8 bytes.\n");

    printf("bit1 = %d, bit2 = %d, num = %d\n", btf.bit1, btf.bit2, btf.num);

    return 0;
}
