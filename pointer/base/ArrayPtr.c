#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t i = 0;
    size_t cnt = 0;

    int a1[10] = {1, 2, 3};

    for(i=0; i<10; i++)
        printf("%d ", a1[i]);
    printf("\n");

    int a2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cnt = sizeof(a2) / sizeof(a2[0]);
    for(i=0; i<cnt; i++)
        printf("%d ", a2[i]);
    printf("\n");


    int a3[10] = {0};
    for(i=0; i<10; i++)
        printf("%d ", a3[i]);
    printf("\n");

    int *ptr = a1;
    for(i=0; i<10; i++)
        printf("%d ", *(ptr+i));
    printf("\n");

    ptr = a2;
    for(i=0; i<10; i++)
        printf("%d ", *(ptr+i));
    printf("\n");

    return 0;
}
