#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *ptr = NULL;
    int dim = 0, i = 0;
    
    printf("Please input dim:");
    scanf("%d", &dim);

    ptr = (double *)malloc(sizeof(double) * dim);
    for(i=0; i<dim; i++)
        *(ptr + i) = (double)(i * i);   
    for(i=0; i<dim; i++)
        printf("ptr[%d] = %lf\n", i, ptr[i]);

    printf("Please input dim again:");
    scanf("%d", &dim);
    free(ptr);

    ptr = (double *)malloc(sizeof(double) * dim);
    for(i=0; i<dim; i++)
        *(ptr + i) = (double)(i * i);   
    for(i=0; i<dim; i++)
        printf("ptr[%d] = %lf\n", i, ptr[i]);

    free(ptr);
    return 0;
}
