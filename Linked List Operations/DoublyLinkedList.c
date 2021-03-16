#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traversal(struct Node *head){
    struct Node *p = head;

    do{
        printf("%d\n",p->data);
        p = p->next;
    }while(p!=NULL);
}

void reversal(struct Node *last){
    struct Node *p = last;

    do{
        printf("%d\n",p->data);
        p = p->prev;
    }while(p!=NULL);
}

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));    
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));    
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));    
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));    

    head->data = 2;
    head->prev = NULL;
    head->next = second;

    second->data = 3;
    second->prev = head;
    second->next = third;

    third->data = 4;
    third->prev = second;
    third->next = fourth;

    fourth->data = 5;
    fourth->prev = third;
    fourth->next = NULL;

    // traversal(head);
    reversal(fourth);

    return 0;
}