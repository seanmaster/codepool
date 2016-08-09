#include <stdio.h>
#include <stdlib.h>

void swap_v(int a, int b)
{
    int c;
    printf("swap_v function initial\n");
    printf("a = %06d, b = %06d\n", a, b);
    printf("&a = %06X, &b = %06X\n", &a, &b);

    c = a;
    a = b;
    b = c;
    
    printf("swap_v function swap end\n");
    printf("a = %06d, b = %06d\n", a, b);
    printf("&a = %06X, &b = %06X\n", &a, &b);
}

int main()
{
    int a = 10;
    int b = 5;

    printf("Before swap in main==\n");    
    printf("a = %06d, b = %06d\n", a, b);
    printf("&a = %06X, &b = %06X\n", &a, &b);

    swap_v(a, b);    
    printf("After swap in main==\n");    
    printf("a = %06d, b = %06d\n", a, b);
    printf("&a = %06X, &b = %06X\n", &a, &b);

    return 0;
}
