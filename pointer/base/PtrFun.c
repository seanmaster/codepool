#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEMOSTRING "Seaddfn"
#define LEN        strlen(DEMOSTRING)
#define TEST_NUM        50000
#define TEST_LOOP       500

char *error3(char *string)
{
    string = (char *)malloc(sizeof(char) * LEN);
    strcpy(string, DEMOSTRING);
    return string;
}

int main()
{
    char *ptr = NULL;
    int i = 0;


    for(i=0;i<TEST_LOOP;i++){
        ptr = error3(ptr);
        if(ptr){
            printf("%s %d\n", ptr, strlen(ptr));
            free(ptr);
        }
    }

    return 0;
}
