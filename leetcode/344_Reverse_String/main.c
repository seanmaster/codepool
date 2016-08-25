#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  reverse string function
 */
char *reverseString(char *s)
{
#if 0
    int len, i, j = 0;
    char *rs;
    len = strlen(s);
    printf("s:%s len: %d\n", s, len);

    rs = (char *)calloc(sizeof(char)*len+1, 1);
    for(i=len-1;i>=0;i--) {
        rs[j++] = s[i];
    }
    rs[j] = '\0';
    printf("rs:%s\n", rs);
    return rs;
#else
    printf("s: %s\n", s);
    char *lc = s;
    char *hc = lc + strlen(lc)-1;
    char tmpc;

    while(lc < hc) {
        tmpc = *lc;
        *lc++ = *hc;
        *hc-- = tmpc;
    }
    printf("rs:%s\n", s);
    return s;
#endif
}
/*
 *  main function
 */
int main(int argc, char **argv)
{
    char *s = NULL;
    char input[1024] = "Trap a rat! Stare Piper at Star apart.";

    s = reverseString(input);

    printf("%s\n", s);
    return 0;
}
