#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 101
#define SWAP(x, y, t)       ((t) = (x), (x) = (y), (y) = (t))

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
    show list content
*/
void show(int list[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers ot generate:");
    scanf("%d", &n);

    if(n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_SUCCESS);
    }

    for(i = 0;i < n; i++) {
        list[i] = rand() % 1000;
    }
    
    printf("Before Sort\n");
    show(list, n);
 
    //select sort
    sort(list, n);

    printf("After Sort\n");
    show(list, n); 

    return 0;
}
