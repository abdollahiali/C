#include <stdio.h>

/*
It plots the histogram of the number of occurences of the digits 0, 1, ..., 9,
the white characters and other characters
*/
int main(void)
{
	int c, i, k, nwhite, nother;
	int ndigit[10];
	printf("This program plots the horizontal histogram of the number of occurences of the digits 0, 1, ..., 9,\n");
	printf("the white characters and other characters*/\n");

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if ( c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;


	for (i = 0; i < 10; ++i) {
		printf("\n%d:", i);
		for (k = 0; k < ndigit[i]; ++k)
			putchar('*');
	}
	printf("\nW:");
	for (k = 0; k < nwhite; ++k)
		putchar('*');
	printf("\nO:");
	for (k = 0; k < nother; ++k)
		putchar('*');

	putchar('\n');
	return(0);
}
