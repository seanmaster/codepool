#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 4

#define X 2
#define Y 3
#define Z 4

int main()
{
    int i = 0, j = 0, k = 0;
    int *ptr1 = NULL;

    int array[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    ptr1 = (int *)malloc(sizeof(int) * ROW * COL);
    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            ptr1[i*COL+j] = array[i][j];

    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            printf("*(ptr1+%d*COL+%d) = %d\n", i, j, *(ptr1+i*COL+j));
    free(ptr1);


    int array3[X][Y][Z] = {{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}},
                          {{12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}}};

    ptr1 = (int*)malloc(sizeof(int)*X*Y*Z);
    for(i=0;i<X;i++)
        for(j=0;j<Y;j++)
            for(k=0;k<Z;k++)
                ptr1[i*Y*Z+j*Z+k] = array3[i][j][k];
    
    for(i=0;i<X;i++)
        for(j=0;j<Y;j++)
            for(k=0;k<Z;k++)
                printf("*(ptr1+%d*Y*Z+%d*Z+%d) = %d\n", i, j, k, *(ptr1+i*Y*Z+j*Z+k));

    free(ptr1);
    return 0;
}
