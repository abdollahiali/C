/*
    Shows that there is no difference between the way that 1-D or 2-D array is saved in memory.

*/
#include <stdio.h>

void show_bytes(unsigned char * ptr_data, unsigned int size)
{
	unsigned int i;

	for(i=0; i<size; i++)
		printf("%.2x ", *(ptr_data+i));
    printf("\n");
}


int main()
{
	/*
		Four ways to initialize arr[2][3]:
		1. arr2[2][3] = {{2, 3, 5}, {7, 11, 13}}
		2. arr2[2][3] = {{2, 3, 5},
						 {7, 11, 13}}
		3. arr2[2][3] = {2, 3, 5, 7, 11, 13}
		4. arr2[2][3] = {2, 3, 5,
						 7, 11, 13}
	*/
	short arr2[2][3] = {{2, 3, 5}, {7, 11, 13}};
	short arr1[6];

	int i, j;

	//print the contents of the array
	printf("\nprint the contents of the 2-D array:\n");
	for(i=0; i<2; i++) {
        for(j=0; j<3; j++)
            printf("%3d ", arr2[i][j]);
        putchar('\n');
	}

    printf("\narray contents of short arr[2][3] = {{2, 3, 5}, {7, 11, 13}} in hex: ");
	show_bytes((unsigned char *) arr2, sizeof(arr2));

	//change 2-D array to 1-D array
    for(i=0; i<2; i++)
        for(j=0; j<3; j++)
            arr1[i*3+j] = arr2[i][j];

    printf("\nprint the contents of the equivalent 1-D array:\n");
    for(i=0; i<6; i++)
        printf("%3d ", arr1[i]);

    printf("\narray contents of short arr[6] = {2, 3, 5, 7, 11, 13} in hex: ");
	show_bytes((unsigned char *) arr1, sizeof(arr1));

	printf("\nAs seen there is no difference between the way a 1-D or a 2-D array are saved in memory.");

    return(0);
}
