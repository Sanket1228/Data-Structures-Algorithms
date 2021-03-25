#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack ptr)
{
    if (ptr.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack ptr)
{
    if (ptr.top == ptr.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // creating normal object 
    struct stack s;
    s.size = 100;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));

    // s.arr[0] = 3;
    // s.top++;

    // creating pointer object
    // struct stack *s;
    // s->size = 100;
    // s->top = -1;
    // s->arr = (int *)malloc(s->size * sizeof(int));

    // s->arr[0] = 3;
    // s->top++;

    if (isEmpty(s))
    {
        printf("Your stack is empty\n");
    }
    else
    {
        printf("Your stack is filled\n");
    }
    return 0;
}