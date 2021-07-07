/*

Print formatted data to stdout using printf

*/
#include <stdio.h>

int main()
{
    int a = -1;
    float f = 17.91, g = 0.00074141791;

    printf("\na = -1\n");
    printf("signed decimal integer,                      %%d: %d\n", a);
    printf("signed decimal integer,                      %%i: %i\n", a);
    printf("unsigned decimal integer,                    %%u: %u\n", a);
    printf("unsigned octal integer,                      %%o: %o\n", a);
    printf("unsigned hexadecimal integer (lowercase),    %%x: %x\n", a);
    printf("unsigned hexadecimal integer (uppercase),    %%X: %X\n", a);

    printf("\nf = 17.91\n");
    printf("floating point (lowercase),       %%f: %f\n", f);
    printf("floating point (uppercase),       %%F: %F\n", f);
    printf("scientific notation (lowercase),  %%e: %e\n", f);
    printf("scientific notation (uppercase),  %%E: %E\n", f);
    printf("shortest form of %%f and %%e,    %%g: %g\n", f);
    printf("shortest form of %%F and %%E,    %%G: %G\n", f);

    printf("\ng = 0.00074141791\n");
    printf("%%f: %f\n", g);
    printf("%%F: %F\n", g);
    printf("%%e: %e\n", g);
    printf("%%E: %E\n", g);
    printf("%%g: %g\n", g);

    g = 0.0000000000000074141791;
    printf("\ng = 0.0000000000000074141791\n");
    printf("%%f: %f\n", g);
    printf("%%e: %e\n", g);
    printf("%%g: %g\n", g);

    printf("\nwidth 20 characters,                 %%20d : %20d\n", a);
    printf("- for left justify,                  %%-20d: %-20d\n", a);
    printf("+ forces sign even if it is positive %%+20d: %+20d\n", a);
    printf("%%20x: %20x\n", a);
    printf("# forces 0x                          %%#20x: %#20x\n", a);
    printf("# forces 0X                          %%#20X: %#20X\n", a);
    printf("# forces start with 0                %%#20o: %#20o\n", a);
    printf("0 forces left pad with zero,         %%020x: %020x\n", a);

    a = 17;
    printf("\na = 17\n");
    printf("%%d     : %d\n", a);
    printf("field of 10 characters,                                       %%10d: %10d\n", a);
    printf(".4 means minimum number of letters (if less pad with zero)  %%10.4d: %10.4d\n", a);

    return 0;
}
