#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s)    \
    if(!((p)=malloc(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

int main(int argc, char **argv)
{
    int *pi;
    float *pf;

    MALLOC(pi, sizeof(int));
    MALLOC(pf, sizeof(float));

    *pi = 1024;
    *pf = 3.14;

    printf("*pi = %d, *pf = %.2f\n", *pi, *pf);

    free(pi);
    free(pf);

    return 0;
}
