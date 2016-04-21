#include <stdio.h>
#include <stdlib.h>

/*
    sum(n) = sum(1, n-1) + n 

    sum(1) = 1
*/

int sum(int n)
{
    if(n == 1)
        return 1;
    else
        return (sum(n-1) + n);
}

int main(int argc, char **argv)
{
    int ret;
    int input1;

    if(argc != 2) {
        printf("Usage %s number1\n", argv[0]);
        exit(1);
    }

    input1 = atoi(argv[1]);
    ret = sum(input1);
    printf("ret = %d\n", ret);

    return 0;
}
