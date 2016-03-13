#include <stdio.h>
#include <stdlib.h>

void swap_by_value(int a, int b)
{
    printf("call by value a's address = %p, b's address = %p\n", &a, &b);
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap_by_address(int *a, int *b)
{
    printf("call by address a's address = %p, b's address = %p\n", a, b);
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv)
{
    int a = 10;
    int b = 20;
    
    printf("a's address = %p, b's address = %p\n", &a, &b);
    
    printf("-------------------\n");
    //Call by value
    printf("Call by value\n");
    printf("Before=>a = %d, b = %d\n", a, b);
    swap_by_value(a, b);
    printf("After=>a = %d, b = %d\n", a, b);
    
    printf("-------------------\n");

    //Call by address
    printf("Call by address\n");
    printf("Before=>a = %d, b = %d\n", a, b);
    swap_by_address(&a, &b);
    printf("After=>a = %d, b = %d\n", a, b);
    return 0;
}
