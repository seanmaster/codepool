#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int i, c = 1, j=0;
    int sum = 0;
    int *renum;
    int *left, *right;

    renum = (int *)calloc(sizeof(int) * digitsSize + 1, 1);
    
    for(i=digitsSize-1; i>=0; i--, j++) {
        sum = c + digits[i];
        c = sum / 10;
        renum[j] = sum % 10;
    }
    if(c >= 1){
        renum[j] = c;
    } else
        j--;
    
    for(i=j;i>=0;i--)
        printf("%d", renum[i]);
    printf("\n");

    *returnSize = j+1;

    left = renum;
    right = renum + *returnSize - 1;
    int tmp;
    while(left < right) {
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }

    printf("returnSize:%d\n", *returnSize);
    
    for(i=0;i<*returnSize;i++)
        printf("%d", renum[i]);
    printf("\n");

    return renum; 
}

int main(int argc, char **argv)
{
    int *num = NULL;
    int digit[] = {9, 9, 9, 9};
    int size;
    int i;

    size = sizeof(digit) / sizeof(int);

    for(i=0; i<size; i++)
        printf("%d", digit[i]);
    printf("\n");

    num = plusOne(digit, size, &size);

    for(i=0; i<size; i++)
        printf("%d", num[i]);
    printf("\n");

    free(num);    
    return 0;
}
