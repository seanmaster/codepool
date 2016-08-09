#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0;
    int row_cnt = 0;
    int col_cnt = 0;

    int a1[3] = {1, 2, 3};
    int a2[2][3] = {{1 ,2, 3},
                    {4, 5, 6}};

    row_cnt = sizeof(a2) / sizeof(a2[0]);
    col_cnt = sizeof(a2[0]) / sizeof(a2[0][0]);

    printf("One dim:");
    int *ptr = &a1[0];
    for(i=0; i<3; i++)
        printf("%d ",*(ptr+i));
    printf("\n");

    printf("Two dim:");
    ptr = &a2[0][0];
    for(i=0; i<row_cnt; i++)
        for(j=0; j<col_cnt; j++)
            printf("%d ", *(ptr+i*col_cnt+j));
    printf("\n");


    return 0;
}
