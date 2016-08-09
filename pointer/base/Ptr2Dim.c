#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 4

int main()
{
    int i = 0, j = 0;
    int **ptr2 = NULL;

    ptr2 = (int **)malloc(sizeof(int *) * ROW);
    for(i=0; i<ROW; i++)
        ptr2[i] = (int*)malloc(sizeof(int) * COL);

    int cnt = 0;
    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            ptr2[i][j] = cnt++;


    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            printf("ptr2[%d][%d] = %d(%0X)\n", i, j, ptr2[i][j], &ptr2[i][j]);

    for(i=0; i<ROW; i++) free(ptr2[i]);
    free(ptr2);

    return 0;
}
