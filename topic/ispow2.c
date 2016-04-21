#include <stdio.h>
#include <stdlib.h>

/*
    Judge input n is pow 2.
*/

int ispow2(int n)
{
    return ((n & -n) == n);
}

int main(int argc, char **argv)
{
    int ret;
    int input;
    
    if(argc != 2) {
        printf("Usage: %s number.\n", argv[0]);
        return -1;
    }
    
    input = atoi(argv[1]);
    ret = ispow2(input);
    
    printf("ret = %d\n", ret);
    return 0;
}
