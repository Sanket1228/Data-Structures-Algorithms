#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

int main(){
    struct node * p1 = createNode(2);  
    struct node * p2 = createNode(3);  
    struct node * p3 = createNode(4);  
    struct node * p4 = createNode(5);  
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;

    return 0;
}