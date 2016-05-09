#include <stdio.h>

#define AAA

int main()
{
    #if defined(AAA) //Same as #ifdef
        printf("AAA\n");
    #else
        printf("BBB\n");
    #endif
    return 0;
}
