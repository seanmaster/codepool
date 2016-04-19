#include <stdio.h>
#include <stdlib.h>

/*
    OR 只要條件不成立，就不會執行後面條件
*/

int main()
{
    int x=2,y=2,z;

    z = ((x=1)||(y=1))?6:8;

    printf("%d %d %d\n", x, y, z);

    return 0;    
}
