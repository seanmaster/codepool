#include <stdio.h>
/*
   給一個數，求因數分解
   note: 質數的乘積
*/
int main()
{
    int a,i,j;
    while (scanf("%d",&a) != EOF) {
        for(j=2; j<a; j++) {
            if(a%j == 0) {
                for(i=0;a%j==0;i++) {
                    a=a/j;
                }
                
                if(i>1) {
                    if(a!=1){
                        printf("%d^%d * ",j,i);
                    }
                    else 
                        printf("%d^%d\n",j,i);  
                }

                if(i==1) {
                    printf("%d * ",j);
                }
            }
        }
        if(a!=1)
            printf("%d\n",a);
    }
    return 0;
}

