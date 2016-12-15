#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Binary Tree Node Structure
typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} * Node;

// my malloc, check if sysyte is out of memory
void *Malloc(size_t n)
{
    void *ptr = malloc(n);
    if(!ptr) {
        fprintf(stderr,"malloc: System out of memory.\n");
        exit(1);
    }
    return ptr;
}

// given an integer, create a Binary Tree Node
Node createNode(int data)
{
    Node node = Malloc(sizeof(struct _node));
    node -> data = data;
    node -> left = node -> right = NULL;

    return node;
}

// insert data into Binary Tree Node
// return inserted Binary Tree Node
Node insertNode(Node root, int data)
{
    if(!root)
        return createNode(data);
    else {
        if(data <= root->data)
            root->left = insertNode(root->left, data);
        else
            root->right = insertNode(root->right, data);
    }
    return root;
}

// search data from Binbary Tree Node
// return matching Node or NULL if not found
Node searchNode(Node root, int data)
{
    if(root) {
        if(root->data == data)
            return root;
        else if(data < root->data)
            return searchNode(root->left, data);
        else
            return searchNode(root->right, data);
    }

    return root;
}

// print Binary Tree Node in preorder
void preorder(Node root)
{
    if(root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// print Binary Tree Node in inorder
void inorder(Node root)
{
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// print Binary Tree Node in postorder
void postorder(Node root)
{
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// prompt menu
void prompt()
{
    printf("Please select from the following:\n"
           "\t* [A]dd data to binary tree.\n"
           "\t* [S]earch data from binary tree.\n"
           "\t* [P]rint binary tree in 3 different order.\n"
           "\t* [C]alculate the max depth.\n"
           "\t* [E]xit.\n"
           "> ");
}

// get integer from user
int getInt()
{
    char line[BUFSIZ+1];
    int n;

    while(1) {
        printf("Please enter a number: ");
        if(fgets(line,BUFSIZ,stdin)) {
            if(sscanf(line, "%d",&n))
                return n;

        } else
            exit(1);
    }
}

// confirm from user
void confirm()
{
    char line[BUFSIZ+1];
    printf("Press 'Enter' to continue...");
    fgets(line,BUFSIZ,stdin);;
}

// calculate the max depth
int maxDepth(Node root)
{
    int left, right;
    if(!root)
        return 0;
    else {
        left = maxDepth(root->left);
        right = maxDepth(root->right);
        return 1 + ((left>right)?left:right);        
    }
}

void deltree(Node root)
{
    if(root) {
        deltree(root->left);
        deltree(root->right);
        free(root);
    }
}

// main function
int main(int argc, char *argv[])
{
    char line[BUFSIZ+1], cmd;
    Node root = NULL,ptr;
    int data;

    while(1) {
        prompt();
        while(fgets(line,BUFSIZ,stdin)) {
            if(sscanf(line, "%c", &cmd)) {
                switch(tolower(cmd)) {
                case 'a':
                    data = getInt();
                    root = insertNode(root, data);
                    printf("\ndata '%d' has added to the binary tree.\n\n", data);
                    confirm();
                    break;
                case 's':
                    data = getInt();
                    ptr = searchNode(root, data);
                    printf("\ndata '%d' is %sfound in binary tree.\n\n", data, (ptr ? "" : "NOT "));
                    confirm();
                    break;
                case 'p':
                    printf("Preorder:\t");
                    preorder(root);
                    printf("\n");
                    printf("Inorder:\t");
                    inorder(root);
                    printf("\n");
                    printf("Postorder:\t");
                    postorder(root);
                    printf("\n\n");
                    confirm();
                    break;
                case 'c':
                    printf("maxDepth:%d\n", maxDepth(root));
                    confirm();
                    break;
                case 'e':
                    printf("Bye!\n");
                    deltree(root);
                    return 0;
                default:
                    printf("Command not found.\n");
                    break;
                }
                break;
            }
        }

    }

    deltree(root);

    return 0;
}

