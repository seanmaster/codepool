#include <stdio.h>
#include <stdlib.h>

void swap_r(int &a, int &b)
{
    int c;
    printf("swap_r function initial\n");
    printf("a = %06d, b = %06d\n", a, b);
    printf("&a = %06X, &b = %06X\n", &a, &b);

    c = a;
    a = b;
    b = c;
    
    printf("swap_r function swap end\n");
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

    swap_r(a, b);    
    printf("After swap in main==\n");    
    printf("a = %06d, b = %06d\n", a, b);
    printf("&a = %06X, &b = %06X\n", &a, &b);

    return 0;
}
