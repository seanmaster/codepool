#include <stdio.h>
#include <stdlib.h>

int add_num(int, int);
int sub_num(int, int);
void cal_num(char *, int, int, int(*)(int, int));

int main()
{
    int x, y;

    printf("Input x:");
    scanf("%d", &x);

    printf("Input y:");
    scanf("%d", &y);

    cal_num("x+y=", x, y, add_num);
    cal_num("x-y=", x, y, sub_num);
    
    
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

void cal_num(char *show, int a, int b, int (*p_func)(int, int))
{
    printf("%s%d\n", show, (*p_func)(a, b));
}
