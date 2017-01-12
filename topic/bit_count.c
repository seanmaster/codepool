#include <stdio.h>
#include <stdlib.h>

unsigned int bit_count_1(unsigned int n)
{
    int count = 0;
    int i;
#if 0     //bad method, can't dill with big number
    for(i=0; i<32; i++) {
        if(n & (1<<i)) {
            count++;
        }
    }
#else //shift input n ont bit.
    /*
    for(; n; n>>=1) {
        if(n & 1)
            count++;
    }
    */
    while(n){
        n &= (n-1);
        count++;
    }
#endif
    
    return count;
}

int main(int argc, char **argv)
{
    unsigned int ret;
    unsigned int input;
    
    if(argc != 2) {
        printf("Usage: %s number.\n", argv[0]);
        return -1;
    }
    
    input = atoi(argv[1]);
    ret = bit_count_1(input);
    
    printf("ret = %d\n", ret);
    return 0;
}
