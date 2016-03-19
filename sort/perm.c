#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t)           ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE       2 

void show(char list[], int n)
{
    int i;
    for(i=0;i<=n;i++)
        printf("%c ", list[i]);
    printf("\n");
}

void perm(char *list, int i, int n)
{
    int j, temp;
    if(i == n) {
        printf("%d\n", __LINE__);
        for(j=0; j<=n; j++) {
            printf("%d\n", __LINE__);
            printf("%c", list[j]);
        }
        printf("    ");
    }   
    else {
        printf("%d\n", __LINE__);
        for(j=i; j<=n; j++) {
            printf("%d\n", __LINE__);
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
            printf("%d\n", __LINE__);
        }
    }
}

int main(int argc, char **argv)
{
    //char list[MAX_SIZE] = {'a', 'b', 'c'};
    char list[MAX_SIZE] = {'a', 'b'};

    perm(list, 0, MAX_SIZE-1);

    return 0;
}
