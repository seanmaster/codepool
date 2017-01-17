#include <stdio.h>
#include <stdlib.h>


int fact(int n)
{
    if(n == 1)
        return 1;
    else
        return fact(n-1)*n;
}

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("%s number\n", argv[0]);
        return -1;
    }

    int n;
    n = atoi(argv[1]);

    printf("%d\n", fact(n));
    return 0;
}
