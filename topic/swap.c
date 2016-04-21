#include <stdio.h>

/*
    swap function
*/
void swap(int *a, int *b)
{
    #if 0 
        int temp;
        temp = *a; *a = *b; *b = temp;
    #else
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    #endif
}

int main(int argc, char **argv)
{
    int a = 10, b = 20;

    printf("Before a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After a = %d, b = %d\n", a, b);

    return 0;
}
