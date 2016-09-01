#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int **pa)
{
    int i;

    printf("pa address %p\n", pa);

    *pa = (int *)malloc(sizeof(int) * 10);
    for(i=0;i<10;i++){
        (*pa)[i] = i;
    }
}

int main()
{
    int i;
    int *a = NULL;
    printf("a address %p\n", &a);

    foo(&a);

    for(i=0;i<10;i++)
        printf("%d ", *(a+i));
    printf("\n");

    return 0;
}
