#include <stdio.h>
#include <stdlib.h>

int add_num(int, int);
int sub_num(int, int);
int max_num(int, int);
int div_num(int, int);

int main()
{
    int x, y;
    int (*p_func)(int, int);
    
    printf("input x:");
    scanf("%d", &x);

    printf("input y:");
    scanf("%d", &y);

    p_func = add_num;
    printf("x + y = %d\n", (*p_func)(x, y));

    p_func = sub_num;
    printf("x - y = %d\n", (*p_func)(x, y));
    
    p_func = max_num;
    printf("x * y = %d\n", (*p_func)(x, y));
    
    p_func = div_num;
    printf("x / y = %d\n", (*p_func)(x, y));

    return 0;
}

int add_num(int x, int y)
{
    return x + y;
}

int sub_num(int x, int y)
{
    return x - y;
}

int max_num(int x, int y)
{
    return x * y;
}

int div_num(int x, int y)
{
    return x / y;
}
