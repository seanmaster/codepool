#include <stdio.h>
#include <stdlib.h>
/*
 *  cut(0) = 1
 *  cut(1) = cut(0) + 1 = 2
 *  cut(2) = cut(1) + 2 = 4
 *  cut(3) = cut(2) + 3 = 7
 *  cut(n) = cut(n-1) + n
 *
 * */
int cut(int n)
{
    if(n == 0)
        return 1;
    else
        return (n + cut(n-1));
}

int main()
{
    int i, n;
    int count = 1;

    scanf("%d", &n);
#if 0    
    for(i=1;i<=n;i++)
        count = count + i;
#endif

    count = cut(n);
    printf("count:%d\n", count);
    return 0;
}
