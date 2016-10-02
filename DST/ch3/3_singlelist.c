#include <stdio.h>
#include <stdlib.h>
#define N 6
struct node{
    int data;
    struct node *link;
};
struct node *front, *rear;

void create_single_list()
{
    front = (struct node *)malloc(sizeof(struct node));
    rear = (struct node *)malloc(sizeof(struct node));
    front->link = NULL;
    rear->link = NULL;
}

void free_single_list()
{
    struct node *temp_node, *this_node;
    
    if(front->link != NULL) {
        this_node = front->link;
        while(this_node->link != NULL) {
            temp_node = this_node;
            this_node = this_node->link;
            free(temp_node);
        }
        free(this_node);
    }
    free(front);
    free(rear);
}

int empty()
{
    if(front->link == NULL)
        return 1;
    else
        return 0;
}

void insert_node(int key)
{
    struct node *new_node, *prev_node, *this_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->link = NULL;
    
    if(front->link == NULL) { //empty list
        front->link = new_node;
        rear->link = new_node;
    }else {
        this_node = front->link;
        if(key < this_node->data) { //insert node to front
            front->link = new_node;
            new_node->link = this_node;
        } else {
            while(this_node->link != NULL) { //insert node to middle
                prev_node = this_node;
                this_node = this_node->link;
                if(key < this_node->data) {
                    prev_node->link = new_node;
                    new_node->link = this_node;
                    return;
                }
            }
            this_node->link = new_node;
            rear->link = new_node;
        }
    }
}

void delete_node(int key)
{
    struct node *prev_node, *this_node, *temp_node;

    prev_node = front;
    this_node = front->link;
    
    while(this_node->link != NULL) {
        if(key == this_node->data) {
            temp_node = this_node;
            prev_node->link = this_node->link;
            free(temp_node);
            return;
        }
        prev_node = this_node;
        this_node = this_node->link;
    }
    
    if(key == this_node->data) {
        temp_node = this_node;
        prev_node->link = NULL;
        rear->link = prev_node->link;
        free(temp_node);
    } else
        printf("Can't fine data %d\n", key);
}

void print_node()
{
    struct node *this_node;
    
    if(!empty()){
        this_node = front->link;
        printf("list content:");
        while(this_node->link != NULL){
            printf("%d ->", this_node->data);
            this_node = this_node->link;
        }   
        printf("%d \n", this_node->data);
    }else
        printf("Empty list!\n");
}

void reverse()
{
    struct node *this_node, *prev_node, *next_node;
    
    next_node = front->link;
    this_node = NULL;
    while(next_node->link != NULL) {
        prev_node = this_node;
        this_node = next_node;
        next_node = next_node->link;
        this_node->link = prev_node;
    }
    next_node->link = this_node;
    front->link = next_node;
}

int main()
{
    int i;
    int a[N] = {5, 65, 31, 83, 78, 21};

    create_single_list();    
    for(i=0; i<N; i++) {
        insert_node(a[i]);
    }
    print_node();

    printf("del [5]...\n");
    delete_node(5);
    print_node();

    printf("del [83]...\n");
    delete_node(83);
    print_node();


    printf("del [31]...\n");
    delete_node(31);
    print_node();

    printf("reverse list...\n");
    reverse();
    print_node();

    printf("reverse list...\n");
    reverse();
    print_node();

    free_single_list();
    return 0;
}
