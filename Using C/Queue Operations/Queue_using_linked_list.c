#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Oueue is full\n");
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (f == NULL)
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}

int dequeue()
{
    struct Node *ptr = f;
    int val = -1;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    // printf("Dequeing element : %d\n",dequeue());
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    linkedListTraversal(f);

    printf("Dequeing element : %d\n",dequeue());
    linkedListTraversal(f);

    return 0;
}