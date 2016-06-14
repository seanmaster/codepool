#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int bigA[MAX];
int bigB[MAX];
int bigR[MAX];

void big_mul(int *rst, int *a, int *b)
{
    int i, j, carry;
    memset(rst, 0, sizeof(int)*MAX); // 先清0
    for(i=0; i<MAX; ++i) {
        if(a[i]==0) continue;
        for(j=0; i+j<MAX; ++j)
            rst[i+j]+= a[i]*b[j];
    }
    // 一次性調整
    for(carry=i=0; i<MAX; ++i) {
        rst[i]+=carry;
        carry = rst[i] / 10;
        rst[i] %= 10;
    }
}

void read_from_string(int *big, char *str)
{
	int i=0, len = strlen(str);
	
	memset(big, 0, sizeof(int)*MAX);
	for(i=len-1; i>=0; --i) {
		big[len-i-1] = str[i] - '0';
	}
	
}

void big_print(int *big)
{
    int i=MAX-1;
    for(i=MAX-1;i>0 && big[i]==0; --i);
		while(i>=0) 
			printf("%d", big[i]), --i;
}

int main()
{
	char A[MAX], B[MAX];
	
	scanf("%s %s", A, B);
	read_from_string(bigA, A);
	read_from_string(bigB, B);
	//big_print(bigA);
	//printf("\n");
	//big_print(bigB);
	//printf("\n");
	big_mul(bigR, bigA, bigB);
	big_print(bigR);
	
	return 0;
}

