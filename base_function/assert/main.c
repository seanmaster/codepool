#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv)
{
    int i = atoi(argv[1]);
    assert(i<100);

    return 0;
}
