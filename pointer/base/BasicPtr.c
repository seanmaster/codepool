#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    int *ptr1;
    printf("ptr1 = %0x\n", ptr1);
    printf("&ptr1 = %0x\n", &ptr1);
    printf("*ptr1 = %0x\n", *ptr1);
*/
    printf("======================================\n");
    int a = 0X10;
    printf("a = %0X\n", a);
    printf("&a = %0X\n", &a);
    //printf("*a = %0X\n", *a);

    printf("======================================\n");
    int *ptr2 = NULL;
    printf("ptr2 = %0X\n", ptr2);
    printf("&ptr2 = %0X\n", &ptr2);
    //printf("*ptr2 = %0X\n", *ptr2);
    
    printf("======================================\n");
    ptr2 = &a;
    printf("ptr2 = %0X\n", ptr2);
    printf("&ptr2 = %0X\n", &ptr2);
    printf("*ptr2 = %0X\n", *ptr2);
    
    return 0;
}
