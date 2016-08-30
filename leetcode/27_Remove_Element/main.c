#include <stdio.h>
#include <stdlib.h>

int removeElement(int *nums, int numsSize, int val)
{
    int i, j;

    i = j = 0;
    for(i=0; i<numsSize; i++) {
        if(nums[i] == val)
            continue;

        nums[j] = nums[i];
        j++;
    }

    return j;
}

int main(int argc, char **argv)
{
    int num, i;
    //int nums[4] = {3, 2, 2, 3};
    int nums[] = {1, 2, 2, 3, 2, 4};
    
    for(i=0; i<sizeof(nums)/sizeof(int); i++)
        printf("%d ", nums[i]);
    printf("\n");

    num = removeElement(nums, sizeof(nums)/sizeof(int), 2);
    printf("num:%d\n", num);

    for(i=0; i<sizeof(nums)/sizeof(int); i++)
        printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
