#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int prec(char a)
{
    if (a == '*' || a == '/')
    {
        return 3;
    }
    else if (a == '+' || a == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

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


void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char *inTopo(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); //creating stack pointer
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));                //creating array in stack to store operator
    char *postfix = (char *)malloc(strlen(infix) + 1 * sizeof(char)); //creating postfix char array to store postfix exp

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i])) //checking if element in infix is operator or not
        {
            postfix[j] = infix[i]; //putting value of that element in postfix array
            i++;
            j++;
        }
        else
        {
            if (prec(infix[i]) > prec(stackTop(sp))) //checking if precedence of ele is greater than top of stack ele or not
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp)) //poping all ele from stack in the postfix array
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = strdup("x-y/z-k*d");
    printf("Post Fix Expression is %s\n", inTopo(infix));
    return 0;
}