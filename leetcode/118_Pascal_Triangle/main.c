#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows, int **columnSizes)
{
    if(numRows == 0)
        return NULL;

    int i, j;
    int **returnArray = NULL;

    returnArray = (int **)calloc(sizeof(int *) * numRows, 1);
    *columnSizes = (int *)calloc(sizeof(int) * numRows, 1);

    for(i=0; i<numRows; i++) {
        (*columnSizes)[i] = i+1;
        returnArray[i] = (int *)calloc(sizeof(int) * (i+1), 1);
        returnArray[i][0] = 1;
        returnArray[i][i] = 1;
        for(j = 1; j < i; j++) {
            returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
        }
    }

    return returnArray;
}

int main(int argc, char **argv)
{
    int i, j;
    int **trangle = NULL;
    int row = 5;
    int *col = NULL;

    trangle = generate(row, &col);

    for(i=0; i<row; i++) {
        for(j=0; j<col[i]; j++)
            printf("%d", trangle[i][j]);
        printf("\n");
    }

    for(i=0; i<row; i++)
        free(trangle[i]);
    free(trangle);
    free(col);

    return 0;
}
