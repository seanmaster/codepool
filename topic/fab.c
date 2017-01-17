#include <stdio.h>
#include <stdlib.h>
/*
 *  fab(n) = fan(n-1) + fab(n-2)
 * */
int fab(int n)
{
#if 0    
    if(n < 3)
        return 1;
    else
        return (fab(n-1) + fab(n-2));
#endif
    int i;
    int n1, n2, temp;
    n1 = 1;
    n2 = 1;
    temp = 0;

    if(n == 1 || n == 2)
        return 1;
    else {
        for(i=0;i<n-2;i++){
            temp = n1;
            n1 = n2;
            n2 = temp + n2;
        }
        return n2;
    }    
}

int main()
{
    int i, n;
    int sum = 1;

    scanf("%d", &n);

    sum = fab(n);
    printf("count:%d\n", sum);
    return 0;
}
