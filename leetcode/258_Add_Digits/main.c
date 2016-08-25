#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addDigits(int num)
{
    int i, len;
    int sum = 0;
    char str[1024] = {0};
    
    while(1) {
        sprintf(str, "%d", num);
        len = strlen(str);
        printf("str:%s len:%d\n", str, len);

        for(i=0; i<len; i++)
            sum = sum + (str[i]-48);

        printf("sum:%d\n", sum);
        if(sum < 10)
            break;
        num = sum;
        sum = 0;
    }
    return sum;
}


int main(int argc, char **argv)
{
    int ret;
    
    ret = addDigits(1111);
    printf("%d\n", ret);
    return 0;
}
