#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC(p, s)    \
    if(!((p)=malloc(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

#define CALLOC(p, n, s) \
    if(!((p) = calloc(n, s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

#define REALLOC(p, s) \
    if(!((p) = realloc(p, s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

int main(int argc, char **argv)
{
    
    printf("//example for malloc\n");
    int *pi;
    float *pf;
    
    MALLOC(pi, sizeof(int));
    MALLOC(pf, sizeof(float));

    *pi = 1024;
    *pf = 3.14;

    printf("*pi = %d, *pf = %.2f\n", *pi, *pf);

    free(pi);
    free(pf);

    printf("\n//example for calloc\n");
    int *qi;
    int i;    
    CALLOC(qi, 5, sizeof(int));

    for(i=0;i<5;i++)
        *(qi+i) = i;

    for(i=0;i<5;i++)
        printf("*(qi+%d) = %d\n", i, *(qi+i));

    free(qi);

    printf("\n//example for realloc\n");
    char *str;
    MALLOC(str, sizeof(char)*15);
    strcpy(str, "123456789abcde");
    printf("String=%s, Address=%p\n", str, str);
   
    REALLOC(str, 25);
    strcat(str, ".com");
    printf("String=%s, Address=%p\n", str, str);
    
    free(str);


    return 0;
}
