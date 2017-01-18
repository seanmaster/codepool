#include <stdio.h>
#include <stdlib.h>

void move(int m, char x, char y, char z)
{
    if(m == 1){
        printf("move one dish from %c move to %c\n", x, z);
    }else{
        move(m-1, x, z, y);
        printf("move one dish from %c move to %c\n", x, z);
        move(m-1, y, x, z);
    }
}

int main()
{
    int n;
    printf("Please enter n number(dishes): \n");
    scanf("%d", &n);

    move(n, 'a', 'b', 'c');


    return 0;
}
