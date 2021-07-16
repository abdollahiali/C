/*
    Creates a file whose name is entered as the second argument (after the name of the program)
    Then, the user can write anything on consule ended with '~' to be saved into the created file.
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    FILE *fp;
    char c;
    if(argc < 2) {
        printf("Error! No file name entered.\n");
        exit(1);
    }

    // otherwise at least there is one name after the name of the program, which is the name of the file to be created
    fp = fopen(argv[1], "w");
	if(!fp) {
		printf("Error! Cannot open the file.\n");
		exit(1);
	}
	
    printf("\nPlease enter what you want to be saved in the file %s and then enter '~'.\n", argv[1]);
    c = getchar();
    while (c != '~') {
        putc(c, fp);
        c = getchar();
    }
	
	fclose(fp);
	printf("Excellent!\n");
    return 0;
}
