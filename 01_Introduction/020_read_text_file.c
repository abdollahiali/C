/*
    Opens a text file, reads its contets and print them, then closes the file
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    FILE *fp;
    
    if(argc < 2) {
        printf("Error! No file name entered.\n");
        exit(1);
    }
    
    fp = fopen(argv[1], "r");
    
    if(!fp) {
        printf("Error! Cannot open the file.\n");
        exit(1);
    }
    
    while(!feof(fp)) // Note: feof() returns non-zero value iff EOF has reached; otherwise, returns zero
        putchar(fgetc(fp));
    
    return 0;
}
