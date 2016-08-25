#include <stdio.h>
#include <stdlib.h>

int getSum(int a, int b)
{
    int carry;
    while(b != 0) {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main(int argc, char **argv)
{
    int s;

    s = getSum(atoi(argv[1]), atoi(argv[2]));
    printf("sum:%d\n", s);
    return 0;
}
