#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    boxa = 0,
    boxb = 1,
    boxc
}BOX;

int main(int argc, char **argv)
{
    printf("%d %d %d\n", boxa, boxb, boxc);

    BOX block_box = boxb;
    printf("%d\n", block_box);

    return 0;
}
