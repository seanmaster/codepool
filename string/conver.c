#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HexToDec(char *s)
{
    char *p = s;

    //空串返回0。
    if(*p == '\0')
        return 0;

    //忽略开头的'0'字符
    while(*p == '0' || *p == 'x' || *p == 'X')
        p++;

    int dec = 0;
    char c;

    //循环直到字符串结束。
    while(c = *p++)
    {
        printf("deal with %c\n", c);
        //dec乘16
        dec <<= 4;

        //数字字符。
        if(c >= '0' && c <= '9')
        {
            dec += c - '0';
        printf("dec = %d\n", dec);        
            continue;
        }

        //小写abcdef。
        if(c >= 'a' && c <= 'f')
        {
            dec += c - 'a' + 10;
        printf("dec = %d\n", dec);        
            continue;
        }

        //大写ABCDEF。
        if(c >= 'A' && c <= 'F')
        {
            dec += c - 'A' + 10;
        printf("dec = %d\n", dec);        
            continue;
        }
        //没有从任何一个if语句中结束，说明遇到了非法字符。
        return -1;
    }

    //正常结束循环，返回10进制整数值。
    return dec;
}

char * DecToHec(int val)
{
    static char hex[20] = {0};
    int i = 0;
    char *p, *q;
    char c;
    printf("val:%d\n", val);
    
    int mod = -1;
    int remain;

    while(mod != 0) {
        mod = val / 16;
        remain = val % 16;
        val = mod;
        if(remain >= 10 && remain<=15) {
            hex[i] = remain + 'A' - 10;
        } else {
            hex[i] = remain + 48;
        }
        i++;
    }
    p = hex;
    q = hex + strlen(hex) - 1;
    while(p < q){
        c = *p;
        *p++ = *q;
        *q-- = c;                    
    }
//    printf("hex:%s\n", hex);
    return hex;
}

int main(int argc, char **argv)
{
    int val;
    char input[20] = {0};
    strcpy(input, argv[1]);
    char *hexs;

    val = HexToDec(input);
    printf("%d\n", val);

    hexs = DecToHec(4877);
    printf("hex:%s\n", hexs);


    return 0;
}
