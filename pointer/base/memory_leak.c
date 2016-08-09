#include <stdio.h>
#include <stdlib.h>

#define ROW 2000
#define COL 4000
#define LOOP 10


int main()
{
    int i = 0, j = 0;
    int **ptr2 = NULL;

    for(i=0; i<LOOP; i++){
        ptr2 = (int **)malloc(sizeof(int *) * ROW);
        for(j=0; j<ROW; j++)
            ptr2[j] = (int *)malloc(sizeof(int) * COL);
        
        system("pause");
    }

    return 0;
}
