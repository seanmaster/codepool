#include <stdio.h>
#include <stdlib.h>

int canWinNim(int n)
{
    return (n % 4);
}

/*
 * main function
 */
int main(int argc, char **argv)
{
    int ret;

    ret = canWinNim(atoi(argv[1]));

    if(ret)
        printf("Can win the game\n");
    else
        printf("Can't win the game\n");
    return 0;
}
