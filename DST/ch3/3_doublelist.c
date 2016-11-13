#include <stdio.h>
#include <stdlib.h>
#define N 6

void create_double_list();
void free_double_list();
int empty();
void insert_node(int key);
void delete_node(int key);
void print_front();
void print_rear();

struct node {
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *front;
struct node *rear;


void create_double_list()
{
    front = (struct node *)malloc(sizeof(struct node));
    rear = (struct node *)malloc(sizeof(struct node));

    front->rlink = NULL;
    rear->rlink = NULL;

}

void free_double_list()
{
    struct node *this_node, *temp_node;
    
    if(!empty()) {
        this_node = front->rlink;
        while(this_node->rlink != NULL) {
            temp_node = this_node;
            this_node = this_node->rlink;
            free(temp_node);
        }
        free(this_node);
    }

    free(front);
    free(rear);
}

int empty()
{
    if(front->rlink == NULL)
        return 1;
    else
        return 0;
}

void insert_node(int key)
{
    struct node *new_node, *this_node, *prev_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->rlink = NULL;
    new_node->llink = NULL;

    if(empty()) {
        front->rlink = new_node;
        rear->rlink = new_node;
        new_node->llink = front;
        new_node->rlink = NULL; //?
    } else {
        this_node = front->rlink;
        if(key < this_node->data) {
            front->rlink = new_node;
            new_node->llink = front;
            new_node->rlink = this_node;
        } else {
            while(this_node->rlink != NULL) { //?
                prev_node = this_node;
                this_node = this_node->rlink;
                if(key < this_node->data) {
                    prev_node->rlink = new_node;
                    new_node->llink = prev_node;
                    new_node->rlink = this_node;
                    this_node->llink = new_node;
                    return;
                }
            }
            this_node->rlink = new_node;
            new_node->llink = this_node;
            new_node->rlink = NULL; //?
            rear->rlink = new_node;
        }
    }
}

void delete_node(int key)
{
    struct node *this_node, *prev_node, *temp_node;

    prev_node = front;
    this_node = front->rlink;

    while(this_node->rlink != NULL) {
        if(key == this_node->data) {
            temp_node = this_node;
            prev_node->rlink = this_node->rlink;
            this_node->rlink->llink = prev_node;
            free(temp_node);
            return;
        }
        prev_node = this_node;
        this_node = this_node->rlink;
    }

    if(key == this_node->data) {
        temp_node = this_node;
        prev_node->rlink = NULL; //?
        rear->rlink = prev_node;
        free(temp_node);
    } else
        printf("Can't find data in list!..\n");
}

/*
    list content: small -> bigger
*/
void print_front()
{
    struct node *this_node;

    if(!empty()) {
        this_node = front->rlink;
        printf("==> list content : ");
        while(this_node->rlink != NULL) {//?
            printf("%d ->", this_node->data);
            this_node = this_node->rlink;
        }
        printf("%d \n", this_node->data);
    } else
        printf("Empty list!\n");
}
/*
    list content: bigger -> small
*/
void print_rear()
{
    struct node *this_node;

    if(!empty()) {
        this_node = rear->rlink;
        printf("==> list content : ");
        while(this_node->llink != front) {
            printf("%d ->", this_node->data);
            this_node = this_node->llink;
        }
        printf("%d \n", this_node->data);
    } else 
        printf("Empty list!\n");
}

int main()
{
    int i;
    int a[N] = {5, 65, 31, 83, 78, 21};

    create_double_list();

    printf("Insert data to double list, keep sort(small->bigger)...\n");
    for(i=0; i<N; i++) {
        printf("step<%d> insert %d\n", i, a[i]);
        insert_node(a[i]);
        print_front();
    }

    printf("delete [5]...\n");
    delete_node(5);
    print_front();

    printf("delete [83]...\n");
    delete_node(83);
    print_front();

    printf("delete [31]...\n");
    delete_node(31);
    print_front();

    printf("fromt rear print out to front(bigger -> small)\n");
    print_rear();


    free_double_list();
    return 0;
}
