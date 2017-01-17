#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n)
{
    int i, v;
    v = sqrt(n);
    for(i=2; i<=v; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("%s number\n", argv[0]);
        return -1;
    }
    int n;
    n = atoi(argv[1]);
    if(checkPrime(n)){
        printf("%d is prime\n", n);
    }else
        printf("%d isn't prime\n", n);


    return 0;
}
