#include <stdio.h>
#include <stdlib.h>

#define Max(x, y)       (x>y?x:y)
#define Min(x, y)       (x<y?x:y)

#ifdef _DEBUG_
int bugs = 0;
#define Error(msg)          {printf(msg);bugs++;}
#endif

int main(int argc, char **argv)
{
    int x = Max(3, 5);
    int y = Min(3, 5);
    printf("max(3, 5)=%d, min(3, 5)=%d\n", x, y);

#ifdef _DEBUG_
    if(x != 5)
        Error("max(3, 5)");    
    if(y != 3)
        Error("min(3, 5)");
    printf("Total %d bugs\n", bugs);
#endif

    return 0;
}
