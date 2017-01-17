#include <stdio.h>
#include <stdlib.h>
/*
 * 8=>1000
 * 15=>1111
 *
 * */
void show_bits(int n)
{
    if((n / 2) != 0){
        show_bits(n/2);
        printf("%d", n%2);
    }else
        printf("%d", n%2);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    show_bits(n);
    return 0;
}
