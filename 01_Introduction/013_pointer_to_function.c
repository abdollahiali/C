#include <stdio.h>

void foo(int v)
{
    printf("The value of v is %d.\n", v);
}

int main(void)
{
    int v = 12345;
    void (*ptr_fun)(int) = foo;
    
    printf("Running foo ordinarily.\n");
    foo(v);
    
    printf("\nPointer to foo is %p.\n", ptr_fun);
    
    printf("\nLet's run foo using pointer to the function.\n");
    (*ptr_fun)(v);
    
    printf("\nLet's run foo using pointer to the function without *.\n");
    ptr_fun(v);
    return 0;
}
