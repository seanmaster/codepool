#include <stdio.h>
#include <stdlib.h>

#define N 6
#define SWAP(x, y, c)        (c=x,x=y,y=c)

int a[N] = {20, 19, 100, 5, 17, 3};
//int a[N] = {1, 2, 3, 4, 5, 6};

void show()
{
    int i;
    printf("Array: ");
    for(i=0; i<N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
/*
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
*/
void bubble_sort()
{
    int i, j;
    int f_swap = 0;
    int temp;
    for(i=0; i<N-1; i++) {
        f_swap = 0;
        for(j=0; j<N-1-i; j++) {
            if(a[j] > a[j+1]){
            //    swap(&a[j], &a[j+1]);
                SWAP(a[j], a[j+1], temp);
                f_swap = 1;
            }
        }
        printf("Step<%d>\n", i);
        show();
        if(!f_swap)
            break;
    }
}

int main()
{
    show();
    bubble_sort();
    show();

    return 0;
}
