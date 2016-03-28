#include <stdio.h>

/*
    運算子優先權陷阱
*/

int main(int argc, char **argv)
{
    int a = 2;
    if(a & 1 == 0)
        printf("Result 1\n");
    else
        printf("Result 2\n");

    return 0;
}
