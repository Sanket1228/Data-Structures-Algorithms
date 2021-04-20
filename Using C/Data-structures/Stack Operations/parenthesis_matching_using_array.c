#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void push(struct stack *sp, char val)
{
    sp->top++;
    sp->arr[sp->top] = val;
}

void pop(struct stack *sp)
{
    sp->top--;
}

int parMatch(char arr[], struct stack *sp)
{
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '(')
        {
            push(sp, arr[i]);
        }
        else if (arr[i] == ')')
        {
            if(sp->top != -1){
                pop(sp);
            }
            else{
                return 0;
            }
        }
    }
    if(sp->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char exp[20] = "((8)(*--$$9))";
    struct stack *s;
    s->size = 20;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int val = parMatch(exp,s);
    if(val == 1){
        printf("Parenthesis Matched\n");
    }
    else{
        printf("Parenthesis Not Matched\n");
    }
    return 0;
}