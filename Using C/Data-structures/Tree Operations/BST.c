#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void display(struct node *root){
    printf("%d",root->data);
    display(root->left);
    display(root->right);
}

int main(){
    struct node *p = createNode(4);
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(7);
    struct node *p4 = createNode(9);
    struct node *p5 = createNode(1);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p4;
    p4->left = p5;
    display(p);
    return 0;
}