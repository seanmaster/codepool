#include <stdio.h>
#include <stdlib.h>

int recur()
{
    char c;
    c = getchar();
    if(c != '\n')
        recur();
    printf("%c", c);
    return 0;
}

int main()
{
    recur();
    return 0;
}
