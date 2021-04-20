#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
        return top;
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        struct Node *n = tp;
        int x = n->data;
        top = tp->next;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;

    for (int i = 0; (i < pos - 1 && pos != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(struct Node *top){
    return top->data;
}

int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}


int main()
{
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    // int ele = pop(top);
    // int pk = peek(3);
    // printf("pop : %d\n",ele);
    // printf("peek : %d\n", pk);
    linkedListTraversal(top);

    printf("Stack Top : %d\n",stackTop(top));
    printf("Stack Bottom : %d\n",stackBottom(top));
    return 0;
}