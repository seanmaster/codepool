#include <stdio.h>
#include <stdlib.h>
#define n 5
#define true 1
#define false 0


int stack[n];
int top = -1;

int empty();
int full();
void push(int stack_data);
int pop();

int empty()
{
    if(top < 0) {
        printf("Stack empty\n");  
        return true;
    } else
        return false;
}

int full()
{
    if(top >= n-1) {
        printf("Stack full\n");
        return true;
    } else
        return false;
}

void push(int stack_data)
{
    stack[++top] = stack_data;
    printf("let %d push to stack\n", stack_data);
}

int pop()
{
    return stack[top--];
}

int main()
{
    int i = 0;
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("==> %d stack...!\n", n);
    printf("==>data 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 push to stack...\n");
    while(! full()) {
        printf("step<%d>:", i+1);
        push(data[i]);
        i++;
    }    
    i = 1;
    printf("==>get data from stack top...\n");
    while(!empty()) {
        printf("step<%d>: get data from stack top: %d\n", i++, pop());
    }

    return 0;
}
