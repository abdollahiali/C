#include <stdio.h>

int main()
{
    int a[3][4];

    int i, j;

    for(i=0; i<3; i++)
        for(j=0; j<4; j++)
            a[i][j] = i*4+j+1;
		
	printf("\n\n---------------  Printing Matrix Using a[i][j]  ----------------\n");
    for(i=0; i<3; i++) {
        for(j=0; j<4; j++)
            printf("%10d", a[i][j]);
        putchar('\n');
    }

    printf("\n\n---------------  Printing Matrix Using pointer  ----------------\n\n");
	
    for(i=0; i<3; i++) {
        for(j=0; j<4; j++)
            printf("%10d", *((int *)a + i*4+j)); // Note that (int *) before 'a' is necessary; because 'a' in 'a[3][4]' is of type 'int (*)[4]'
        putchar('\n');
    }

    return(0);
}
