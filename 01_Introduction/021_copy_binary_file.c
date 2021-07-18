#include <stdio.h>
#include <stdlib.h>

// copy_binary_file src_file dest_file
// Creates dest_file and copies the src_file into it

int main(int argc, char *argv[])
{
    FILE *fp_src, *fp_dest;
    char c;
    if(argc < 3) {
        printf("Error! Needs two file names.\n");
        exit(1);
    }

    // otherwise at least there is two file names after the name of the program
    fp_src = fopen(argv[1], "rb");
	if(!fp_src) {
		printf("Error! Cannot open the file to read.\n");
		exit(1);
	}
    
	fp_dest = fopen(argv[2], "wb");
	if(!fp_dest) {
		printf("Error! Cannot create or open the file to write into.\n");
		exit(1);
	}
	

    long long unsigned int cntr = 0;
    
	while(!feof(fp_src)) {
        cntr++;
		fputc(fgetc(fp_src), fp_dest);
    }
	
	fclose(fp_src);
	fclose(fp_dest);
	
	printf("File copied (size: %llu bytes)\n", cntr);
    return 0;
}