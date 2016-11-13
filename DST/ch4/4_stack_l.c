#include <stdio.h>
#include <stdlib.h>
#define n 10
#define null 0

void create_stack();
void free_stack();
int empty();
void push(int stack_data);
int pop();

struct node{
    int data;
    struct node *link;
};
struct node *top;

void create_stack()
{
    top = (struct node *)malloc(sizeof(struct node));
    top->link = null;
    printf("==> Create a empty stack!\n");
}

void free_stack()
{
    struct node *x, *y;
    
    if(top->link != null){
        x = top->link;
        while(x->link != null){
            y = x;
            x = x->link;
            free(y);
        }
        free(x);
    }
    free(top);
}

int empty()
{
    if(top->link == null)
        return 1;
    else
        return 0;
}

void push(int stack_data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = stack_data;
    new_node->link = top->link;
    top->link = new_node;    

    printf("push %d in stack\n", stack_data);
}

int pop()
{   
    int data;
    struct node *x;
    x = top->link;
    top->link = x->link;
    data = x->data;
    free(x);
    return data;
}

int main()
{
    int i;
    int data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    create_stack();
    printf("==>push 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 to stack.....\n");
    for(i=0; i<n; i++){
        printf("step<%d>:", i+1);
        push(data[i]);
    }

    i = 1;
    printf("\n==>Get data from stack...\n");
    while(!empty()){
        printf("step<%d>: pop out data %d from stack\n", i++, pop());
    }

    free_stack();
    return 0;
}
