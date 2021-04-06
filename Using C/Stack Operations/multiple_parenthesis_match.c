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

char pop(struct stack *sp)
{
    int val = sp->arr[sp->top];
    sp->top--;
    return val;
}

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int multiparMatch(char arr[], struct stack *sp)
{
    char popped_ch;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            push(sp, arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            if (sp->top == -1)
            {
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,arr[i])){
                return 0;
            }
        }
    }
    if (sp->top == -1)
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
    char exp[20] = "[4-6]((8){(9-8}]";
    struct stack *s;
    s->size = 20;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    int val = multiparMatch(exp, s);
    if (val == 1)
    {
        printf("Parenthesis Matched\n");
    }
    else
    {
        printf("Parenthesis Not Matched\n");
    }
    return 0;
}