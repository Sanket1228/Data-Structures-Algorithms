#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head){
    struct Node *p = head;
    do
    {
        printf("%d\n", p->data);
        p = p->next;
    } while (p!=head);
    
}

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;    
}
//Inserting Element at last is same as at First

struct Node *insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
    }
    
    ptr->next = p->next;
    p->next = ptr;
    return head;    
}



int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));    
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));    
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));    
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));    

    head->data = 2;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 4;
    third->next = fourth;
    fourth->data = 5;
    fourth->next = head;

    // head = insertAtFirst(head,8);
    head = insertAtIndex(head,8,2);
    traversal(head);
    
    return 0;
}