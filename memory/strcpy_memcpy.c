#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(int argc, char **argv)
{
    int i;
    char str1[5] = {'a', 'b', 'c', '\0', 'd'};
    char str2[5] = {0};

    printf("Source string=>\n");
    for(i=0;i<5;i++)
        printf("%c\n", str1[i]);

    printf("strcpy result\n");
    strcpy(str2, str1);
    for(i=0;i<5;i++)
        printf("%c\n", str2[i]);

    
    printf("memcpy result\n");
    memcpy(str2, str1, 5);
    for(i=0;i<5;i++)
        printf("%c\n", str2[i]);

    return 0;
}
