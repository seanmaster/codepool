#include <stdio.h>
#include <stdlib.h>

/*
    n! = n * (n-1)! =>fact(n) = n * fact(n-1)

    0! = 1
*/

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return (n * fact(n - 1));
}

int main(int argc, char **argv)
{
    int ret;
    int input;

    if(argc != 2) {
        printf("Usage %s number\n", argv[0]);
        exit(1);
    }

    input = atoi(argv[1]);
    ret = fact(input);
    printf("ret = %d\n", ret);

    return 0;
}
