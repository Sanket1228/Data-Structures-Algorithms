#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow ! \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty ! \n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int pos){
    int arrayInd = ptr->top - pos + 1;
    if(arrayInd < 0){
        printf("Not valid index \n");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);  
    push(sp,7);
    push(sp,8);

    // printf("pop : %d\n",pop(sp));
    // printf("pop : %d\n",pop(sp));
    printf("peek : %d\n",peek(sp,4));
    printf("Stack Top : %d\n",stackTop(sp));
    printf("Stack Bottom : %d\n",stackBottom(sp));
    return 0;
}