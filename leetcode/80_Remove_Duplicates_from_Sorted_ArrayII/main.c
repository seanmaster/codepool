#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
    int i, j, c = 0;
    if(numsSize == 0)
        return 0;

    j = 0;
    for(i=1; i<numsSize; i++) {
        if(nums[j] == nums[i]) {
            c++;
            if(c < 2)
                nums[++j] = nums[i];
        } else {
            nums[++j] = nums[i];
            c = 0;
        }
    }
    return j+1;    
}

int main(int argc, char **argv)
{
    int num, i;
    //int nums[] = {1, 1, 2};
    int nums[] = {1, 1, 1, 2, 2, 3};


    for(i=0; i<sizeof(nums)/sizeof(int); i++)
        printf("%d ", nums[i]);
    printf("\n");

    num = removeDuplicates(nums, sizeof(nums)/sizeof(int));    
    printf("num:%d\n", num);

    for(i=0; i<sizeof(nums)/sizeof(int); i++)
        printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
