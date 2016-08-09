#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0, k = 0;
    int cnt = 0;
    int row_cnt = 0;
    int col_cnt = 0;

    int a1[2][3] = {{1, 2, 3},
                    {4, 5, 6}};
    int a2[2][3] = {{1, 2},
                    {4}};
    int a3[][3] = {{1, 2, 3},
                   {4, 5, 6}};

    int a4[2][3][4] = {{{1, 1, 1, 1},{2, 2, 2, 2},{3, 3, 3, 3}},
                       {{4, 4, 4, 4},{5, 5, 5, 5},{6, 6, 6, 6}}};

    printf("a4:");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            for(k=0;k<4;k++)
                printf("%d ", a4[i][j][k]);
    printf("\n");


    printf("a1:");
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            printf("%d ", a1[i][j]);
        printf("\n");

    printf("a2:");
    for(i=0; i<2; i++)
        for(j=0; j<3; j++)
            printf("%d ", a2[i][j]);
        printf("\n");

    printf("a3:");
    for(i=0; i<2; i++)
        for(j=0; j<3; j++)
            printf("%d ", a3[i][j]);
        printf("\n");

    cnt = sizeof(a3) / sizeof(a3[0][0]);
    row_cnt = sizeof(a3) / sizeof(a3[0]);
    col_cnt = sizeof(a3[0]) / sizeof(a3[0][0]);

    printf("cnt = %d\n", cnt);
    printf("row_cnt = %d\n", row_cnt);
    printf("col_cnt = %d\n", col_cnt);


    return 0;
}
