#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveZeroes(int *nums, int numsSize)
{
    int i, j = 0, c = 0;
    int *intlist = NULL;
    int *pi = nums;

    intlist = (int *)calloc(sizeof(int) * numsSize, 1);
#if 0
    for(i=0; i<numsSize; i++)
        printf("%d ", nums[i]);
    printf("\n");
#endif
    //pick up non-zero integer
    for(i=0; i<numsSize; i++) {
        if(*pi == 0)
            c++;
        else {
            intlist[j++] = *pi;
//            printf("pi = %d\n", *pi);
        }
        pi++;
    }

    //padding zero integer.
    for(i=0; i<c; i++) {
        intlist[j++] = 0;
    }

#if 0    
    for(i=0; i<j; i++)
        printf("%d ", intlist[i]);
    printf("\n");
#endif
    
    for(i=0; i<numsSize; i++)
        nums[i] = intlist[i];    

    free(intlist);
}

int main(int argc, char **argv)
{
    int i;
    int nums[6] = {0, 1, 0, 3, 0, 12};

    for(i=0; i<6; i++)
        printf("%d ", nums[i]);
    printf("\n");
    
    moveZeroes(nums, 6);    

    for(i=0; i<6; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
