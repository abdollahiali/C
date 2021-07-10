/*
	In this program we show that the name of an array (which itself is a pointer)
	and the pointer of the first element of array are the same
	and we see the values in their exact hex form (as stored in memory)

	Example:
	int arr[] = {2, 3, 5, 7, 11};

    arr == &arr[0]
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
	int arr[] = {2, 3, 5, 7, 11};

	// print the hex (little endian) version of the array
	printf("\narray contents {2, 3, 5, 7, 11} in hex: ");
	show_bytes((unsigned char *) arr, sizeof(arr));

	// print the pointer to the first element of the array
	int *ptr = &arr[0];
	printf("\npointer of the first element of the array: ");
	show_bytes((unsigned char *) &ptr, sizeof(ptr));

	// pointer to the array (that is the name of the array)
	printf("\npointer to the array (that is the name of the array): ");
	int *ptr1 = arr;
	show_bytes((unsigned char *) &ptr1, sizeof(ptr1));
    
    
	printf("\npointer to the second element of the array (if little endian the first element (othewise the last element) has increased by 4): ");
	int *ptr2 = ptr1;
    ptr2++;
	show_bytes((unsigned char *) &ptr2, sizeof(ptr2));

    return(0);
}
