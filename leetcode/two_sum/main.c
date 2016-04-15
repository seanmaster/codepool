#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int i, j;
    int *list;

    list = (int *)malloc(sizeof(int) * 2);
    
    for(i=0; i<numsSize; i++) {
        for(j=i+1; j<numsSize; j++) {
            if((nums[i]+nums[j]) == target) {
                list[0] = i;
                list[1] = j;
                return list;
            }
        }
    }
    return NULL;
}

/**
 * show the nums list content.
 */
void show(int nums[], int num, int target)
{
    int i;

    printf("target = %d\n", target);
    printf("nums = ");
    for(i=0; i<num; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int i;
    int *list;
    int nums[5] = {1, 2, 3, 4, 5};
    int target = 7;
    
    show(nums, 5, target);

    list = twoSum(nums, 5, target);
    
    if(list != NULL) {
        printf("nums[%d] + nums[%d] = %d\n", list[0], list[1], target);
    } else
        printf("Can't find the match item\n");

    free(list);
    return 0;
}
