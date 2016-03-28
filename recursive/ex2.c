#include <stdio.h>
#include <stdlib.h>

/*
    a * b = a * (b-1) + a

    a * 1 = a 
*/

int mult(int a, int b)
{
    if(b == 1)
        return a;
    else
        return (mult(a, b-1) + a);
}

int main(int argc, char **argv)
{
    int ret;
    int input1, input2;

    if(argc != 3) {
        printf("Usage %s number1 number2\n", argv[0]);
        exit(1);
    }

    input1 = atoi(argv[1]);
    input2 = atoi(argv[2]);
    ret = mult(input1, input2);
    printf("ret = %d\n", ret);

    return 0;
}
