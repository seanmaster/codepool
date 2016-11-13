#include <stdio.h>
#include <stdlib.h>

#define n 100
#define true 1
#define false 0

int stack[n][4];
int top = -1;

int empty();
int full();
void push(int disk_no, char source, char intermediate, char destination);
void pop(int *disk_no, char *source, char *intermediate, char *destination);
void print_stack_data();
void swap(char *x, char *y);
void hanoi(int disk_no, char source, char intermediate, char destination);

int empty()
{
    if(top < 0)
        return true;
    else
        return false;
}

int full()
{
    if(top >= n-1)
        return true;
    else
        return false;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void print_stack_data()
{
    int i;
    printf("Stack content:\n");
    if(top >= 0){
        for(i=top; i>=0; i--)
            printf("Stack(%d)=%d %c %c %c\n", i, stack[i][0], stack[i][1], stack[i][2], stack[i][3]);
    }else
        printf("Empty stack!\n");
}

void push(int disk_no, char source, char intermediate, char destination)
{
    top = top + 1;
    stack[top][0] = disk_no;
    stack[top][1] = source;
    stack[top][2] = intermediate;
    stack[top][3] = destination;
    printf("push data %d %c %c %c in stack\n", disk_no, source, intermediate, destination);
    
    print_stack_data();
}

void pop(int *disk_no, char *source, char *intermediate, char *destination)
{
    *disk_no = stack[top][0];
    *source = stack[top][1];
    *intermediate = stack[top][2];
    *destination = stack[top][3];
    top = top - 1;
    printf("get data from stack: %d %c %c %c\n", *disk_no, *source, *intermediate, *destination);
    print_stack_data();
}

void hanoi(int disk_no, char source, char intermediate, char destination)
{
    int step = 0;

    printf("move process:\n");
    while(1){
        while(disk_no > 1){
            push(disk_no, source, intermediate, destination);
            disk_no -= 1;
            swap(&intermediate, &destination);
        }
        printf("==>Step<%d>: #%d disk move from #%c to #%c.\n", ++step, disk_no, source, destination);
        if(empty()) break;
        else{
            pop(&disk_no, &source, &intermediate,&destination);

            printf("**>step<%d>: #%d disk move from #%c to #%c\n", ++step, disk_no, source, destination);
            disk_no -= 1;
            swap(&source, &intermediate);
        }
    }
}

int main()
{
    int disk_no;
    printf("==> %d size stack\n", n);
    printf("How many disk?");
    scanf("%d", &disk_no);
    hanoi(disk_no, 'a', 'b', 'c');
    return 0;
}
