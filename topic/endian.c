#include <stdio.h>

int main()
{
    int x = 1;
    char *y = (char*)&x;
    
    if((*y+48) == '1')    
        printf("Little endian\n");
    else
        printf("Big endian\n");
    //printf("%d %c\n",*y, *y+48);

    return 0;
}
