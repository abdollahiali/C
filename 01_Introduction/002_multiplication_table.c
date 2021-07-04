#include "stdio.h"

int main(void)
{
	int x, y, z;
	printf("The multiplication table:\n");
	for (x = 1; x <= 10; ++x){

		for (y = 1; y <= 10; ++y){
			printf("%6d", x*y);
		}
		printf("\n");
	}
}
