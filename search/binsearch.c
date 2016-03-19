#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SWAP(x, y, t)           ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y)           ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))
#define MAX_SIZE 10
/*
    show list content
*/
void show(int list[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}
/*
    select sort
*/
void sort(int list[], int n)
{
    int i, j, min, temp;
    for(i=0; i<n; i++) {
        min = i;
        for(j=i+1; j<n; j++) {
            if(list[j] < list[min])
                min = j;
        }
        SWAP(list[i], list[min], temp);
    }
}
/*
    binarysearch
*/
int binarysearch(int list[], int searchnum, int left, int right)
{
    int middle;

#if 0    
    while(left <= right) {
        middle = (left + right) / 2;
        switch(COMPARE(list[middle], searchnum)) {
            case -1:
                left = middle + 1;
                break;
            case 0:
                return middle;
            case 1:
                right = middle - 1;
                break;
        }
    }
    return -1;
#else // use recursive method.
    if(left <= right) {
        middle = (left + right) / 2;
        switch(COMPARE(list[middle], searchnum)) {
            case -1: return binarysearch(list, searchnum, middle+1, right);
            case 0: return middle;
            case 1: return binarysearch(list, searchnum, left, middle-1);
        }
    }
#endif
}

int main(int argc, char **argv)
{
    int n, ret;
    int left, right;
    int list[MAX_SIZE] = {4, 3, 6, 1, 10, 20, 55, 88, 199, 101};

    printf("Befort sort\n");
    show(list, MAX_SIZE);

    //select sort
    sort(list, MAX_SIZE);

    printf("After sort\n");
    show(list, MAX_SIZE);

    printf("Enter you want to search number:");
    scanf("%d", &n);
        
    //binary search
    left = 0;
    right = MAX_SIZE - 1;
    ret = binarysearch(list, n, left, right);

    if(ret != -1)
        printf("the number:%d find ln list[%d]\n", n, ret);
    else
        printf("Can't find the number:%d in list\n", n);

    return 0;
}
