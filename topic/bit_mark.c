#include <stdio.h>
#include <stdlib.h>

/*
    mark the bit_5 to 1 in input n.
*/

unsigned int bit_mark(unsigned int n)
{
    return (n | (1 << 4));
}

int main(int argc, char **argv)
{
    unsigned int new_n;
    unsigned int input;
    
    if(argc != 2) {
        printf("Usage: %s number.\n", argv[0]);
        return -1;
    }
    
    input = atoi(argv[1]);
    new_n = bit_mark(input);
    
    printf("new number = %d\n", new_n);
    return 0;
}
