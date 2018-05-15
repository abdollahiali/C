#include <stdio.h>

/* 
It plots the vertical histogram of the number of occurences of the digits 0, 1, ..., 9,
the white characters and other characters
*/

int main(void)
{
	int c, i, k, nwhite, nother, max_occur = 0, indicator;
	int ndigit[10];
	printf("This program plots the vertical histogram of the number of occurences of the digits 0, 1, ..., 9,\n");
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

	// finding the maximum occurance of the characters
	for (i = 0; i < 10; ++i)
		if (ndigit[i] > max_occur)
			max_occur = ndigit[i];
	if (nwhite > max_occur)
		max_occur = nwhite;
	if (nother > max_occur)
		max_occur = nother;
	printf("max: %d", max_occur);
	printf("\n^\n|");
	for (i = 0; i < max_occur; ++i) {
		printf("\n|");
		indicator = max_occur - i;
		for (k = 0; k < 10; ++k)
			if (indicator <= ndigit[k])
				printf(" *");
			else
				printf("  ");
		if (indicator <= nwhite)
			printf(" *");
		else
			printf("  ");
		if (indicator <= nother)
			printf(" *");
		else
			printf("  ");
	}
	printf("\n- - - - - - - - - - - - - >");
	printf("\n  0 1 2 3 4 5 6 7 8 9 W O\n");
	return(0);	
}


