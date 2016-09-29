#include <stdio.h>
#include <stdlib.h>

#define N 6

//struct
struct node{
	int data;
	struct node *link;
};
struct node *front, *rear;

void create_empty_queue()
{
	front = (struct node *)malloc(sizeof(struct node));
	rear = (struct node *)malloc(sizeof(struct node));
	front->link = NULL;
	rear->link = NULL;
}	

void insert_info_queue(int key)
{
	struct node *new_node, *temp_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = key;
	new_node->link = NULL;

	if(front->link == NULL){
		front->link = new_node;
		rear->link = new_node;
	}else{
		temp_node = rear->link;
		temp_node->link = new_node;
		rear->link = new_node;
	}
}

int empty()
{
	if(front->link == NULL)
		return 1;
	else
		return 0;
}

int delete_from_queue()
{
	int key;
	struct node *temp_node;

	temp_node = front->link;
	front->link = temp_node->link;
	key = temp_node->data;
	free(temp_node);
	return key;
}

void free_all_queue()
{
	struct node *this_node, *temp_node;

	if(front->link != NULL){
		this_node = front->link;
		while(this_node->link != NULL){
			temp_node = this_node;
			this_node = this_node->link;
			free(temp_node);
		}
		free(this_node);
	}
	free(front);
	free(rear);
}

int main()
{
	int i;
	int a[N] = {0, 1, 2, 3, 4, 5};

	create_empty_queue();
	printf("放資料在queue的尾端...\n");
	for(i=0; i<N ;i++){
		printf("步驟<%d> 放入%d\n", i, a[i]);
		insert_info_queue(a[i]);
	}

	printf("從queue中取出資料...\n");
	i = 0;
	while(!empty())
		printf("步驟<%d> 取出%d\n", i++, delete_from_queue());

	free_all_queue();
	return 0;
}
