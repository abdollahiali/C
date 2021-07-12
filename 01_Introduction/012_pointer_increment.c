/*
    It shows the effect of increment on pointers.
*/
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

int main(void)
{
    int i;
    struct node nd;
    int *ptr_i = &i;
    struct node *ptr_nd = &nd;
    
   printf("\n\
   We have:\n\
   \tint i;\
   \n\tstruct node {\n\
    \t\tint data;\n\
    \t\tstruct node *next;\n\
    \t};\n\n");
    

    printf("ptr_i: %p", ptr_i);
    printf("\nThe pointer to the place after the int value is %ld bytes later:", sizeof(i));
    printf("\nptr_i + 1: %p", ptr_i+1);

    printf("\n\nptr_nd: %p", ptr_nd);
    printf("\nThe pointer to the place after the structure node is %ld bytes later:", sizeof(nd));
    printf("\nptr_nd + 1: %p\n", ptr_nd+1);
    
    printf("\nThe difference between ptr_nd (%p) and ptr_i (%p) is %d bytes\n", ptr_nd, ptr_i, (int)((char *)ptr_nd-(char *)ptr_i));
    printf("\nWhy is that?\n");

    return 0;
}