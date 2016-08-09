#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
    int i;
    int array[MAX];
    for(i=0; i<MAX; i++) array[i] = i;

    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("array[%d] = %d\n", i, array[i]);

    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("*(array+%d) = %d\n", i, *(array+i));

    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("&array[%d] = %0X\n", i, &array[i]);

    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("(array+%d) = %0X\n", i, (array+i));


    /*
        Method 1

        int *ptr1 = array;
    */

    /*
        Method 2

        int *ptr1 = NULL;
        ptr1 = array;
    */

    //Method 3
    int *ptr1 = &(array[0]);
    
    printf("=========================\n");
    printf("ptr1 = %0X\n", &ptr1);

    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("ptr1[%d] = %d\n", i, ptr1[i]);

    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("*(ptr1+%d) = %d\n", i, *(ptr1+i));
    
    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("&ptr1[%d] = %0X\n", i, &ptr1[i]);


    printf("=========================\n");
    for(i=0; i<MAX; i++) printf("(ptr1+%d) = %0X\n", i, (ptr1+i));

    return 0;
}
