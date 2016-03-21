#include <stdio.h>
#include <stdlib.h>

char *strcpy_(char *dest, char *src)
{
    while(*dest++ = *src++);
    return dest;
}

int main(int argc, char **argv)
{
    char src[128] = "hello my name is sean";
    char dest[128] = {0};

    strcpy_(dest, src);

    printf("%s\n", dest);
    return 0;
}
