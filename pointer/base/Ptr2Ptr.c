#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0X10;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;


    printf("a = %06X ptr1 = %06X ptr2 = %06X\n", a, ptr1, ptr2);
    printf("&a = %06X &ptr1 = %06X &ptr2 = %06X\n", &a, &ptr1, &ptr2);
    printf("XXXXXXXXX *ptr1 = %06X *ptr2 = %06X\n", *ptr1, *ptr2);
        
    printf("==========Get a's value======\n");   
    printf("a = %06X\n", a); 
    printf("*ptr1 = %06X\n", *ptr1);
    printf("**ptr2 = %06X\n", **ptr2);

    printf("==========Get a's address======\n");
    //&a = ptr1 = *ptr2
    printf("&a = %06X\n", &a);
    printf("ptr1 = %06X\n", ptr1);
    printf("*ptr2 = %06X\n", *ptr2);


    printf("==========Get ptr1's address======\n");
    //&ptr1 = ptrw
    printf("&ptr1 = %06X\n", &ptr1);
    printf("ptr2 = %06X\n", ptr2);

    return 0;
}
