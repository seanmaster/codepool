#include <stdio.h>
#include <stdlib.h>

/*
    Change every bit in input n.
*/

int bit_not(int n)
{
    return (~n);
}

int main(int argc, char **argv)
{
    int new_n;
    int input;
    
    if(argc != 2) {
        printf("Usage: %s number.\n", argv[0]);
        return -1;
    }
    
    input = atoi(argv[1]);
    new_n = bit_not(input);
    
    printf("new number = %d\n", new_n);
    return 0;
}
