#include <stdio.h>
#include <stdlib.h>

#define N 6

struct node{
    int data;
    struct node *link;
};

struct node *front_1, *rear_1;
struct node *front_2, *rear_2;
struct node *front_3, *rear_3;

void create_list_1()
{
    front_1 = (struct node *)malloc(sizeof(struct node));
    rear_1 = (struct node *)malloc(sizeof(struct node));

    front_1->link = NULL;
    rear_1->link = NULL;
}

void create_list_2()
{
    front_2 = (struct node *)malloc(sizeof(struct node));
    rear_2 = (struct node *)malloc(sizeof(struct node));

    front_2->link = NULL;
    rear_2->link = NULL;
}

void create_list_3()
{
    front_3 = (struct node *)malloc(sizeof(struct node));
    rear_3 = (struct node *)malloc(sizeof(struct node));

    front_3->link = NULL;
    rear_3->link = NULL;
}

void insert(int key, struct node *front_, struct node *rear_)
{
    struct node *new_node, *temp_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->link = NULL;

    if(front_->link == NULL) {
        front_->link = new_node;
        rear_->link = new_node;
    } else {
        temp_node = rear_->link;
        temp_node->link = new_node;
        rear_->link = new_node;
    }
}

void length(struct node *front_)
{
    int count = 0;
    struct node *this_node;

    if(front_->link != NULL) {
        this_node = front_->link;
        while(this_node->link != NULL) {
            count++;
            this_node = this_node->link;
        }
        count++;
        printf("length: %d\n", count);
    } else {
        printf("length: 0\n");
    }

}

void concatenate(struct node *front_x, struct node *rear_x,
                 struct node *front_y, struct node *rear_y,
                 struct node *front_z, struct node *rear_z)
{
    struct node *this_node;

    if(front_x->link == NULL) {
        front_z->link = front_y->link;
        rear_z->link = rear_y->link;
    } else {
        if(front_y->link == NULL) {
            front_z->link = front_x->link;
            rear_z->link = rear_x->link;
        } else {
            front_z->link = front_x->link;
            this_node = rear_x->link;
            this_node->link = front_y->link;
            rear_z->link = rear_y->link;    
        }
    }
}

void print(struct node *front_)
{
    struct node *this_node;

    if(front_->link != NULL) {
        this_node = front_->link;
        printf("list:");
        while(this_node->link != NULL) {
            printf("%d ->", this_node->data);
            this_node = this_node->link;
        }
        printf("%d \n", this_node->data);
    } else {
        printf("Empty list!!!\n");
    }
}

void free_single_list()
{
    struct node *this_node, *temp_node;

    if(front_1->link != NULL) {
        this_node = front_1->link;
        while(this_node->link != NULL) {
            temp_node = this_node;
            this_node = this_node->link;
            free(temp_node);
        }
        free(this_node);
    }
    free(front_1);
    free(rear_1);

    if(front_2->link != NULL) {
        this_node = front_2->link;
        while(this_node->link != NULL) {
            temp_node = this_node;
            this_node = this_node->link;
            free(temp_node);
        }
        free(this_node);
    }
    free(front_2);
    free(rear_2);

    if(front_3->link != NULL) {
        this_node = front_3->link;
        while(this_node->link != NULL) {
            temp_node = this_node;
            this_node = this_node->link;
            free(temp_node);
        }
        free(this_node);
    }
    free(front_3);
    free(rear_3);
}

int main()
{
    int i;
    int a[N] = {0, 1, 2, 3, 4, 5};
    int b[N] = {10, 11, 12, 13, 14, 15};

    create_list_1();
    create_list_2();
    create_list_3();

    for(i=0; i<N; i++) {
        insert(a[i], front_1, rear_1);
    }
    printf("Single list [1]...\n");
    print(front_1);
    length(front_1);

    for(i=0; i<N; i++) {
        insert(b[i], front_2, rear_2);
    }
    printf("\nSingle list [2]...\n");
    print(front_2);
    length(front_2);

    printf("\nSingle list [3]...\n");
    print(front_3);
    length(front_3);

   
    printf("\nMvrge list1 & list2...\n");
    concatenate(front_1, rear_1, front_2, rear_2, front_3, rear_3);
    print(front_3);
    length(front_3);
 
    free_single_list();
    return 0;
}
