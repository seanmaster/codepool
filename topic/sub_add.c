#include <stdio.h>
#include <stdlib.h>

#define BIT_MATH   1 

int sub_one(int n)
{
    #if BIT_MATH
        return ~-n;
    #else
        return --n;
    #endif
}

int add_one(int n)
{
    #if BITMATH
        return -~n;
    #else
        return ++n;
    #endif

}

int main(int argc, char **argv)
{
    int i = 10;
    printf("i = %d\n", i);
    printf("add one %d\n", add_one(i));
    printf("sub one %d\n", sub_one(i));

    return 0;
}
