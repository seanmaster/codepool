#include <stdio.h>
#include <stdlib.h>

#define EXAMPLE     3 //1: basic 2:use function call 3:typedef function pointer

int doAdd(int a, int b)
{
    return a + b;
}

int doMinus(int a, int b)
{
    return a - b;
}

int Math_Call(int (*my_func_ptr)(int, int), int a, int b)
{
    return my_func_ptr(a, b);
}

typedef int (*MY_FUNC_PTR)(int, int);
int Math_Call2(MY_FUNC_PTR func_ptr, int a, int b)
{
    return func_ptr(a, b);
}

int main(int argc, char **argv)
{
    int a = 5, b = 3;
    
    printf("a = %d, b = %d\n", a, b);

    if(EXAMPLE == 1) {
        printf("Method 1: basic used");
        int (*my_func_ptr)(int, int);
        
        my_func_ptr = doAdd;
        printf("function pointer to doAdd => %d\n", (*my_func_ptr)(a, b));
        my_func_ptr = doMinus;
        printf("function pointer to doAdd => %d\n", (*my_func_ptr)(a, b));
    } else if(EXAMPLE == 2) {
        printf("Method 2: Use function call\n");
        
        printf("function pointer to doAdd => %d\n", Math_Call(doAdd, a, b));
        printf("function pointer to doMinus => %d\n", Math_Call(doMinus, a, b));
    } else if(EXAMPLE == 3) {
        printf("Method 3: typedef function pointer\n");
        
        printf("function pointer to doAdd => %d\n", Math_Call2(doAdd, a, b));
        printf("function pointer to doMinus => %d\n", Math_Call2(doMinus, a, b));
    }

    return 0;
}
