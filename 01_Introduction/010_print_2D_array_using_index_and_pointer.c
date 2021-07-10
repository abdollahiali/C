/*
	Prints the contents of a 2-D array  uisng indexing and also using pointers
    Also print it in the oriignal hex form as stored in the memory

	We use the followig 2-D array as an example:
	short arr[2][3] = {{2, 3, 5}, {7, 11, 13}};

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
	short arr[2][3] = {{2, 3, 5}, {7, 11, 13}};
	int i, j;

	//print the contents of the array
	printf("\nprint the contents of the 2-D array:\n");
	for(i=0; i<2; i++) {
        for(j=0; j<3; j++)
            printf("%3d ", arr[i][j]);
        putchar('\n');
	}

	printf("\nprint the contents of the 2-D array using pointer:\n");
    for(i=0; i<2; i++) {
        for(j=0; j<3; j++)
            printf("%3d ", *((short *)arr + 3*i + j));
        putchar('\n');
	}

	printf("\nprint the contents of the 2-D array using pointer [print both pointer and content (ptr, content)]:\n");
    for(i=0; i<2; i++) {
        for(j=0; j<3; j++)
            printf("(%10p, %3d) ", (short *)arr + 3*i + j, *((short *)arr + 3*i + j));
        putchar('\n');
	}

	printf("\nNote that the pointer arr+1 has the value of %p\n", arr+1);

    printf("\nTherefore, we can write the (ptr, content) using (short *)(arr+i) + j and its contents:\n");
    for(i=0; i<2; i++) {
        for(j=0; j<3; j++)
            printf("(%10p, %3d) ", (short *)(arr+i)+j, *((short *)(arr+i)+j));
        putchar('\n');
	}

	// print the hex (little endian) version of the array
	printf("\narray contents of short arr[2][3] = {{2, 3, 5}, {7, 11, 13}} in hex: ");
	show_bytes((unsigned char *) arr, sizeof(arr));
	

    return(0);
}
