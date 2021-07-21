/*
Negative of INT_MIN equals INT_MIN.
This is the case for any two's complement integer. That is the negative of minimum value of w-byte two's complement is equalt to itself.
*/
#include <stdio.h>
#include <limits.h>

int main()
{
	int i = INT_MIN;
	printf(" INT_MIN = %d\n", i);
	printf("-INT_MIN = %d\n", -i);
	printf("Note that they are equal.\n");
	return 0;
}